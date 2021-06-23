/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:08:43 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/23 17:08:45 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/stat.h>
#include <fcntl.h>

char *recurs(int depth, int *ret, int fd)
{
	char c;
	char *out;
	if (!read(fd, &c, 1))
		c = 0;
	if (c == '\n' || c == 0)
	{
		out = malloc(sizeof(char) * depth + 1);
		out[depth] = 0;
		*ret = 1;
		if (c == 0)
			*ret = 0;
		return out;
	}
	else
	{
		out = recurs(depth + 1, ret, fd);
		out[depth] = c;
	}
	return out;
}

int get_next_line(char **out)
{
	int ret = 1;
	//int fd = open("hugo.txt", O_RDONLY);
	*out = recurs(0, &ret, 0);
	//close(fd);
	return ret;
}

// int main()
// {
// 	char *line;
// 	int ret = 1;

// 	while ((ret = get_next_line(&line)))
// 		printf("%d: %s\n", ret, line);
// 	return 0;
// }
