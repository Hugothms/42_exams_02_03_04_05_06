/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:29:21 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/24 16:51:28 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(1);
}

void fatal()
{
	error("error: fatal\n");
	exit(1);
}

int	size_cmd_char(char **cmd, char *str)
{
	if (!cmd)
		return 0;
	int i = -1;
	while(cmd[++i])
		if (!strcmp(cmd[i], str))
			return i;
	return i;
}

char	**add_cmd(char **argv, int *i)
{
	int size = size_cmd_char(&argv[*i], ";");
	if(!size)
		return NULL;
	char **cmd = malloc(sizeof(*cmd) * (size + 1));
	int j = -1;
	while(++j < size)
		cmd[j] = argv[*i + j];
	cmd[j] = NULL;
	*i += size;
	return cmd;
}

char **find_next_pipe(char **cmd)
{
	if (!cmd)
		return NULL;
	int i = -1;
	while (cmd[++i])
		if (!strcmp(cmd[i], "|"))
			return &cmd[i + 1];
	return NULL;
}

void exec_cmd(char **cmd, char **env)
{
	pid_t pid;
	if ((pid = fork()) < 0)
		fatal();
	if (!pid)
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

void execute(char **cmd, char **env)
{
	if (!find_next_pipe(cmd))
		return exec_cmd(cmd, env);
	int fd_in;
	int fd_pipe[2];
	int nb_wait = 0;
	int pid;

	if ((fd_in = dup(STDIN_FILENO)) < 0)
		fatal();
	while(cmd)
	{
		if (pipe(fd_pipe) < 0 || (pid = fork()) < 0)
			fatal();
		if (!pid)
		{
			if (dup2(fd_in, STDIN_FILENO) < 0)
				fatal();
			if (find_next_pipe(cmd))
			{
				if (dup2(fd_pipe[1], STDOUT_FILENO) < 0)
					fatal();;
			}
			close(fd_in);
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			cmd[size_cmd_char(cmd, "|")] = NULL;
			exec_cmd(cmd, env);
			exit(0);
		}
		else
		{
			if (dup2(fd_pipe[0], fd_in) < 0)
				fatal();
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			nb_wait++;
			cmd = find_next_pipe(cmd);
		}
	}
	close(fd_in);
	while (nb_wait-- >= 0)
		waitpid(0, NULL, 0);
}

void builtin_cd(char **cmd)
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

int main(int argc, char **argv, char **env)
{
	char	**cmd = NULL;
	int 	i = 0;

	while(++i < argc)
	{
		if (!(cmd = add_cmd(argv, &i)))
			continue;
		if (!strcmp(cmd[0], "cd"))
			builtin_cd(cmd);
		else
			execute(cmd, env);
	}
	return 0;
}
