/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:45:26 by vlow              #+#    #+#             */
/*   Updated: 2024/11/24 20:09:44 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

t_flags	init_flags(void);
int	sp_load(va_list vlist, t_flags *flags);
int	sp_flags(va_list vlist, const char **fptr);
int	sp_type(const char *c, t_flags *flags);
void	fl_set_precision(const char **c, t_flags *flags);
void	fl_set_width(const char **c, t_flags *flags);

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
			count += sp_flags(vlist, &fptr);
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

int	sp_flags(va_list vlist, const char **fptr)
{
	// const char	*tptr;
	t_flags flags;

	flags = init_flags();
	// tptr = *fptr;
	// while (*tptr)
	// {
		// if (sp_type(*fptr, &flags))
			// break ;
	// 	tptr++;
	// }
	// flags.buffer = ft_substr(*fptr, 0, (tptr - *fptr) + 1);
	// if (!flags.buffer)
	// 	return (0);
	// *fptr = tptr + 1;
	if (!sp_type(*fptr, &flags))
		return (0);
	return (sp_load(vlist, &flags));
	// while (*tptr == '-' || *tptr == '0' || *tptr == '.' ||
	// 	   *tptr == '#' || *tptr == '+' || *tptr == ' ')
	// {
	// }
}

int	sp_load(va_list vlist, t_flags *flags)
{
	if (flags->specifier == 'c')
		return (sp_c(vlist, flags));
}

int	sp_type(const char *c, t_flags *flags)
{
	while (*c)
	{
		if (*c == 'c' || *c == 's' || *c == 'p' || *c == 'd' || *c == 'i'
			|| *c == 'u' || *c == 'x' || *c == 'X' || *c == '%')
		{
			flags->specifier = *c;
			return (*c);
		}
		if (*c == '-')
			flags->left_align = 1;
		else if (*c == '0' && flags->width == 0 && flags->precision == -1)
			flags->zero_pad = 1;
		else if (*c == ' ')
			flags->space = 1;
		else if (*c == '#')
			flags->hash_hex = 1;
		else if (*c == '+')
			flags->show_sign = 1;
		else if (*c == '.')
			fl_set_precision(&c, flags);
		else if (ft_isdigit(*c))
			fl_set_width(&c, flags);
		c++;
	}
	return (0);
}

void	fl_set_precision(const char **c, t_flags *flags)
{
	if (**c == '.')
		(*c)++;
	if (ft_isdigit(**c))
	{
		flags->precision = ft_atoi(*c);
		while (ft_isdigit(**c))
			(*c)++;
	}
	else
		flags->precision = 0;
}

void	fl_set_width(const char **c, t_flags *flags)
{
	if (**c >= '1' && **c <= '9')
	{
		flags->width = ft_atoi(*c);
		while (ft_isdigit(**c))
			(*c)++;
	}
}

t_flags	init_flags(void)
{
	t_flags flags;

	flags.left_align = 0;
	flags.zero_pad = 0;
	flags.hash_hex = 0;
	flags.show_sign = 0;
	flags.space = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.specifier = '\0';
	return (flags);
}

int main(void)
{
	char *str = "world";
	int n = 123;

	int i = ft_printf("hello [%s] and [%d].\n", str, n);
	printf("%d", i);


	return (0);
}
