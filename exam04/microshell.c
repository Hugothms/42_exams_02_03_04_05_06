/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:08:53 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/24 14:55:58 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void ft_putchar_err(char c)
{
	write(STDERR_FILENO, &c, 1);
}

void error(char* str)
{
	while (*str)
		ft_putchar_err(*str++);
}

void fatal()
{
	error("error: fatal\n");
	exit(1);
}

/**
 * @return The size of cmd until cmd[i] == str (useful for ";" and "|")
**/
int size_cmd_char(char** cmd, char *str)
{
	if (!cmd)
		return 0;
	int	i = -1;
	while (cmd[++i])
		if (!strcmp(cmd[i], str))
			return i;
	return i;
}

/**
 * @return A char** containing a copy of av[i] until next ";"
**/
char** add_cmd(char** av, int *i)
{
	int	size = size_cmd_char(&av[*i], ";"); // size of new char** until next ";". We start from i position
	if (!size)
		return NULL; // case ";" ";" with nothing between them
	char** tmp = NULL;
	if (!(tmp = malloc(sizeof(*tmp) * (size + 1))))
		fatal();
	int	j = -1;
	while (++j < size)
		tmp[j] = av[j + *i];
	tmp[j] = NULL;
	*i += size; // adds the number of elements copied, av[i] will be on the next ";"
	return tmp;
}

// Executes a command
void exec_cmd(char** cmd, char** env)
{
	pid_t	pid;
	if ((pid = fork()) < 0)
		fatal();
	if (!pid) // son
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			error("error: cannot execute ");
			error(cmd[0]);
			error("\n");
			exit(1);
		}
	}
	waitpid(0, NULL, 0);
}

/**
 *  @return A char** pointing just after the first pipe the func will meet
**/
char** find_next_pipe(char** cmd)
{
	if (!cmd)
		return NULL;
	int i = -1;
	while (cmd[++i])
		if (!strcmp(cmd[i], "|"))
			return &cmd[i + 1];
	return NULL;
}

void execute(char** cmd, char** env)
{
	/* CASE NO PIPES */
	if (!find_next_pipe(cmd))
		return exec_cmd(cmd, env);
	/* CASE PIPES */
	int		fd_in;
	int		fd_pipe[2];
	// char**	tmp = cmd;
	int		nb_wait = 0;
	pid_t	pid;

	if ((fd_in = dup(STDIN_FILENO)) < 0)
		fatal();
	while (cmd)
	{
		if (pipe(fd_pipe) < 0 || (pid = fork()) < 0)
			fatal();
		if (!pid) // Son do the pipes and then execute only the part of the command before next pipe.
		{

			if (dup2(fd_in, STDIN_FILENO) < 0)
				fatal();
			if (find_next_pipe(cmd) && dup2(fd_pipe[1], STDOUT_FILENO) < 0) // If there is still a pipe after this command
				fatal();
			close(fd_in); // Closing all fds to avoid leaking files descriptors
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			cmd[size_cmd_char(cmd, "|")] = NULL; // Replaces first pipe met with NULL (modifying cmd in the son, cmd in the parent is still the same!)
			exec_cmd(cmd, env);
			exit(0);
		}
		else // Parent is just saving fd_pipe[0] for next son's execution and correctly closing pipes
		{
			if (dup2(fd_pipe[0], fd_in) < 0) // Really important to protect syscalls using fd, tests with wrong fds will be done during grademe
				fatal();
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			++nb_wait;
			cmd = find_next_pipe(cmd); // Goes to the next command to be executed, just after first pipe met
		}
	}
	close(fd_in); // closing last dup2 that happen in the last parent loop tour
	while (nb_wait-- >= 0) // waiting for each command launched to bed executed
		waitpid(0, NULL, 0);
}

void builtin_cd(char** cmd)
{
	if (!cmd[1] || cmd[2])
		return error("error: cd: bad arguments\n");
	if (chdir(cmd[1]) < 0)
	{
		error("error: cd: cannot change directory to ");
		error(cmd[1]);
		error("\n");
	}
}

int main(int ac, char** av, char** env)
{
	char**	cmd = NULL;
	int		i = 0;
	while (++i < ac)
	{
		if (!(cmd = add_cmd(av, &i))) // cmd = command until next ";". i is increased of the size of cmd, av[i] will now be equal to next ";"
			continue;
		if(!strcmp(cmd[0], "cd"))
			builtin_cd(cmd);
		else
			execute(cmd, env);
		free(cmd);
	}
	return 0;
}
