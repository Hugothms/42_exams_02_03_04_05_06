#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

typedef struct		s_client
{
	int				fd;
	int				id;
	struct s_client	*next;
}					t_client;

t_client	*clients = NULL;
int			sockfd, g_id = 0;
fd_set		sockets, cpy_read, cpy_write;
char		msg[42*4096], buff[42*4096 + 42];

void fatal()
{
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	close(sockfd);
	exit(1);
}

int get_id(int fd)
{
	t_client	*tmp = clients;

	while (tmp)
	{
		if (tmp->fd == fd)
			return tmp->id;
		tmp = tmp->next;
	}
	return -1;
}

int get_max_fd()
{
	t_client	*tmp = clients;
	int			max_fd = sockfd;

	while (tmp)
	{
		if (tmp->fd > max_fd)
			max_fd = tmp->fd;
		tmp = tmp->next;
	}
	return max_fd;
}

void send_all(int fd)
{
	t_client	*tmp = clients;

	while (tmp)
	{
		if (tmp->fd != fd && FD_ISSET(tmp->fd, &cpy_write))
		{
			if (send(tmp->fd, buff, strlen(buff), 0) < 0)
				fatal();
		}
		tmp = tmp->next;
	}
}

void add_client()
{
	struct sockaddr_in	cli;
	int					connfd;
	socklen_t			len = sizeof(cli);
	t_client			*new;

	if ((connfd = accept(sockfd, (struct sockaddr *)&cli, &len)) < 0)
		fatal();
	bzero(&buff, sizeof(buff));
	sprintf(buff, "server: client %d just arrived\n", g_id);
	send_all(connfd);
	FD_SET(connfd, &sockets);
	if (!(new = calloc(1, sizeof(*new))))
		fatal();
	new->fd = connfd;
	new->id = g_id++;
	new->next = NULL;
	if (!clients)
		clients = new;
	else
	{
		t_client	*tmp = clients;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void rm_client(int fd)
{
	t_client	*to_del;

	bzero(&buff, sizeof(buff));
	sprintf(buff, "server: client %d just left\n", get_id(fd));
	send_all(fd);
	if (clients && clients->fd == fd)
	{
		to_del = clients;
		clients = clients->next;
	}
	else
	{
		t_client	*tmp = clients;
		while (tmp && tmp->next && tmp->next->fd != fd)
			tmp = tmp->next;
		if (tmp && tmp->next && tmp->next->fd == fd)
		{
			to_del = tmp->next;
			tmp->next = tmp->next->next;
		}
	}
	free(to_del);
	FD_CLR(fd, &sockets);
	close(fd);
}

void extract_msg(int fd)
{
	char	tmp[42*4096];
	int		i = 0;
	int		j = 0;

	bzero(&tmp, sizeof(tmp));
	while (msg[i])
	{
		tmp[j] = msg[i];
		j++;
		if (msg[i] == '\n')
		{
			bzero(&buff, sizeof(buff));
			sprintf(buff, "client %d: %s", get_id(fd), tmp);
			send_all(fd);
			j = 0;
			bzero(&tmp, sizeof(tmp));
		}
		i++;
	}
	bzero(&msg, sizeof(msg));
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}

	struct sockaddr_in	servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		fatal();
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal();
	if (listen(sockfd, 128) != 0)
		fatal();

	FD_ZERO(&sockets);
	FD_SET(sockfd, &sockets);
	bzero(&buff, sizeof(buff));
	bzero(&msg, sizeof(msg));
	while (1)
	{
		cpy_write = cpy_read = sockets;
		if (select(get_max_fd() + 1, &cpy_read, &cpy_write, NULL, NULL) < 0)
			continue;
		for (int fd = sockfd; fd < get_max_fd() + 1; fd++)
		{
			if (FD_ISSET(fd, &cpy_read))
			{
				if (fd == sockfd)
				{
					add_client();
					break;
				}
				int	ret_recv = 1000;
				while (ret_recv == 1000 || msg[strlen(msg) - 1] != '\n')
				{
					ret_recv = recv(fd, msg + strlen(msg), 1000, 0);
					if (ret_recv <= 0)
						break ;
				}
				if (ret_recv <= 0)
				{
					rm_client(fd);
					break;
				}
				extract_msg(fd);
			}
		}
	}
	return 0;
}
