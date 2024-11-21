/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:45:26 by vlow              #+#    #+#             */
/*   Updated: 2024/11/21 17:49:12 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

void	ft_putstr(char *str);
int	sp_type(va_list vlist, const char c);
int	sp_s(va_list vlist);
int	bs_esc(const char c);
int	sp_d(va_list vlist);

int	ft_printf(const char *format, ...)
{
	int count;
	va_list vlist;
	const char *fptr;

	count = 0;
	fptr = format;
	va_start(vlist, format);

	while (*fptr)
	{
		count++;
		if (*fptr == '%')
		{
			fptr++;
			count += sp_type(vlist, *fptr);
			fptr++;
		}
		if (*fptr == '\\')
		{
			fptr++;
			count += bs_esc(*fptr);
			fptr++;
		}
		write(1, &*fptr, 1);
		fptr++;
	}
	return (count);
}

int	bs_esc(const char c)
{
	if (c == 'n')
	{
		write(1, "\n", 1);
		return (1);
	}
	if (c == 'r')
	{
		// do sumting
	}
	return (0);
}

int	sp_type(va_list vlist, const char c)
{
	if (c == 's')
	{
		return (sp_s(vlist));
	}
	if (c == 'd')
	{
		return (sp_d(vlist));
	}
	return (0);
}

int	sp_d(va_list vlist)
{
	int idx;

	idx = va_arg(vlist, int);
	ft_putnbr_fd(idx, 1);
	return (ft_countdigits(idx));
}

int	sp_s(va_list vlist)
{
	char *str;

	str = va_arg(vlist, char *);
	if (str)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}


int main(void)
{
	char *str = "world";
	int n = 123;

	int i = ft_printf("hello [%s] and [%d].\n", str, n);
	printf("%d", i);


	return (0);
}
