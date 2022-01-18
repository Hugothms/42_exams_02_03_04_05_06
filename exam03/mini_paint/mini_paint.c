/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:08:27 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/18 17:45:33 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

typedef struct drawing {
	int		width;
	int		height;
	char	*buff;
} drawing;

typedef struct circle {
	char	type;
	float	x;
	float	y;
	float	radius;
	char	color;
} circle;

int ft_strlen(char *str)
{
	int i = 0;
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

	int scan_ret = fscanf(file, "%d %d %c\n", &drawing->width, &drawing->height, &background);
	if (scan_ret == 3)
	{
		if (drawing->width < 1 || drawing->width > 300 || drawing->height < 1 || drawing->height > 300)
			return (1);
		drawing->buff = (char *)malloc(drawing->width * drawing->height);
		if (!drawing->buff)
			return (1);
		int i = 0;
		while (i < drawing->width * drawing->height)
			drawing->buff[i++] = background;
		return (0);
	}
	return (1);
}

float square(float a)
{
	return (a * a);
}

float dist_2_points(float x1, float y1, float x2, float y2)
{
	float dist_x = square(x1 - x2);
	float dist_y = square(y1 - y2);
	return sqrtf(dist_x + dist_y);
}

int is_in_circle(float x, float y, circle *circle)
{
	float distance_sqrt = dist_2_points(x, y, circle->x, circle->y);
	float distance = distance_sqrt - circle->radius;
	if (distance > 0.0)
		return (0); // Outside
	if (distance > -1.0)
		return (2); // Border
	return (1); // Inside
}

void execute_one(circle *circle, drawing *drawing, int x, int y)
{
	int is_in;

	is_in = is_in_circle((float)x, (float)y, circle);
	if (is_in == 2 || (is_in == 1 && circle->type == 'C'))
		drawing->buff[x + y * drawing->width] = circle->color;
}

int apply_op(circle *circle, drawing *drawing)
{
	if (circle->radius <= 0.0 || (circle->type != 'C' && circle->type != 'c'))
		return (1);
	for (size_t i = 0; i < drawing->width; i++)
		for (size_t j = 0; j < drawing->height; j++)
			execute_one(circle, drawing, i, j);
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
	int 	scan_ret;
	circle 	circle;
	drawing	drawing;

	if (!parse(file, &drawing))
	{
		while ((scan_ret = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.color)) == 5)
		{
			if (apply_op(&circle, &drawing))
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
