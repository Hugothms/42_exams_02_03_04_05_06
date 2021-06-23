/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:08:32 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/23 17:16:06 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char *ft_strdup(char *in, int len)
{
	if (len == -1)
		len = ft_strlen(in);
	int i = 0;
	char *out;
	if (!(out = malloc(sizeof(char) * len + 1)))
		return 0;
	while (i < len)
	{
		out[i] = in[i];
		i++;
	}
	out[i] = 0;
	return out;
}

int is_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int ft_atoi(char *str)
{
	int res = 0;
	int i = 0;
	while (is_nbr(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return res;
}

char *itoabase(long nb, char *base)
{
	long cp = nb;
	int len = 0;
	int p = 0;
	int sign = 1;
	int baselen = ft_strlen(base);
	if (cp < 0)
	{
		sign = -1;
		len++;
		cp *= -1;
	}
	else if (cp == 0)
		return (ft_strdup("0", -1));
	while (cp > 0)
	{
		cp = cp / baselen;
		len++;
	}
	char *out;
	if (!(out = malloc(sizeof(char) * len + 1)))
		return 0;
	if (sign == -1)
	{
		nb *= -1;
		out[p++] = '-';
		len++;
	}
	while (nb > 0)
	{
		out[len - ++p] = base[nb % baselen];
		nb = nb / baselen;
	}
	out[len] = 0;
	return out;
}

char *joinfill(char *in, char c, int nb)
{
	int i = -1;
	char *out;
	if (!(out = malloc(sizeof(char) * (ft_strlen(in) + nb + 1))))
		return 0;
	while (++i < nb)
		out[i] = c;
	int j = 0;
	while (in[j])
		out[i++] = in[j++];
	out[i] = 0;
	free(in);
	return out;
}

void processdx(va_list args, int *written, int prec, int width, char c)
{
	long val;
	char *out;
	if (c == 'x')
	{
		val = (long)va_arg(args, unsigned int);
		out = itoabase(val, "0123456789abcdef");
	}
	else if (c == 'd')
	{
		val = (long)va_arg(args, int);
		out = itoabase(val, "0123456789");
	}
	if (prec > ft_strlen(out))
	{
		if (val < 0)
			out[0] = '0';
		out = joinfill(out, '0', prec - ft_strlen(out) + (val < 0));
		if (val < 0)
			out[0] = '-';
	}
	if (width > ft_strlen(out))
		out = joinfill(out, ' ', width - ft_strlen(out));
	*written = *written + ft_strlen(out);
	write(1, out, ft_strlen(out));
	free(out);
}

void processs(va_list args, int *written, int prec, int width)
{
	long val;
	char *out;
	out = ft_strdup(va_arg(args, char *), -1);
	if (prec < ft_strlen(out))
	{
		char *tmp;
		tmp = ft_strdup(out, prec);
		free(out);
		out = tmp;
	}
	if (width > ft_strlen(out))
		out = joinfill(out, ' ', width - ft_strlen(out));
	*written = *written + ft_strlen(out);
	write(1, out, ft_strlen(out));
	free(out);
}

int process(char *str, va_list args, int *written)
{
	int i = 1;
	int prec = -1;
	int width = -1;
	if (is_nbr(str[i]))
		width = ft_atoi(str + i);
	while (is_nbr(str[i]))
		i++;
	if (str[i] == '.' && ++i)
		prec = ft_atoi(str + i);
	while (is_nbr(str[i]))
		i++;
	if (str[i] == 'd' || str[i] == 'x')
		processdx(args, written, prec, width, str[i]);
	if (str[i] == 's')
		processs(args, written, prec, width);
	return i + 1;
}

int ft_printf(char *str, ...)
{
	int i = 0;
	va_list args;
	va_start(args, str);
	int written = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += process(str + i, args, &written);
		else if (++written)
			write(1, str + i++, 1);
	}
	return written;
}

// int main()
// {
// 	char *s = "Hello World";
// 	int val2 = printf("Sample text %0x %100.3s\n", 23, s);
// 	int val = ft_printf("Sample text %0x %100.3s\n", 23, s);
// 	printf("%d %d\n", val, val2);
// 	return 0;
// }
