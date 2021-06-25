/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:08:29 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/25 16:12:19 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct drawing {
    int		width;
    int		height;
    char	*buff;
} drawing;

typedef struct rectangle {
    char	type;
    float	x;
    float	y;
    float	width;
    float	height;
    char	color;
} rectangle;

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int parse(FILE *file, drawing *drawing)
{
	char	background;

	if (fscanf(file, "%d %d %c\n", &drawing->width, &drawing->height, &background) == 3)
	{
		if (drawing->width < 1 || drawing->width > 300 || drawing->height < 1 || drawing->height > 300)
			return (1);
		drawing->buff = (char *)malloc(drawing->width * drawing->height);
		if (!drawing->buff)
			return (1);
		for (int i = 0; i < drawing->width * drawing->height; i++)
			drawing->buff[i] = background;
		return (0);
	}
	return (1);
}

int is_in_rectangle(float x, float y, rectangle *rectangle)
{
	if (x < rectangle->x || rectangle->x + rectangle->width < x || y < rectangle->y || rectangle->y + rectangle->height < y)
		return (0); // Outside
	if (x - rectangle->x < 1.0 || rectangle->x + rectangle->width - x < 1.0 ||
		y - rectangle->y < 1.0 || rectangle->y + rectangle->height - y < 1.0)
		return (2); // Border
	return (1); // Inside
}

void execute_one(rectangle *rect, drawing *drawing, int x, int y)
{
	int is_in;

	is_in = is_in_rectangle((float)x, (float)y, rect);
	if (is_in == 2 || (is_in == 1 && rect->type == 'R'))
		drawing->buff[x + y * drawing->width] = rect->color;
	return;
}

int apply_op(rectangle *rect, drawing *drawing)
{
	if (rect->width <= 0.0 || rect->height <= 0.0 || (rect->type != 'R' && rect->type != 'r'))
		return (1);
	for (size_t i = 0; i < drawing->width; i++)
		for (size_t j = 0; j < drawing->height; j++)
			execute_one(rect, drawing, i, j);
	return (0);
}

void print_drawing(drawing *drawing)
{
	for (size_t i = 0; i < drawing->height; i++)
	{
		write(1, drawing->buff + i * drawing->width, drawing->width);
		write(1, "\n", 1);
	}
}

int execute(FILE *file)
{
	int 		scan_ret;
	rectangle	rect;
	drawing		drawing;

	if (!parse(file, &drawing))
	{
		while ((scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.color)) == 6)
		{
			if (apply_op(&rect, &drawing))
				return (1);
		}
		if (scan_ret == -1)
		{
			print_drawing(&drawing);
			return (0);
		}
	}
	return (1);
}

int main(int argc, char **argv)
{
	FILE	*file;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file && !execute(file))
			return (0);
		ft_putstr("Error: Operation file corrupted\n");
	}
	else
		ft_putstr("Error: argument\n");
	return (1);
}
