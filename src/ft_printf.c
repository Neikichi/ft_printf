/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:45:26 by vlow              #+#    #+#             */
/*   Updated: 2024/11/23 17:15:11 by vlow             ###   ########.fr       */
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
int	sp_type(const char c, t_flags *flags);

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
	const char	*tptr;
	t_flags flags;

	flags = init_flags();
	tptr = *fptr;
	while (*tptr)
	{
		if (sp_type(*tptr, &flags))
			break ;
		tptr++;
	}
	flags.buffer = ft_calloc((tptr - *fptr) + 2, sizeof(char));
	if (!flags.buffer)
		return (0);
	ft_strlcpy(flags.buffer, *fptr, (tptr - *fptr) + 2);
	*fptr = tptr + 1;
	return (sp_load(vlist, &flags));
	// while (*tptr == '-' || *tptr == '0' || *tptr == '.' ||
	// 	   *tptr == '#' || *tptr == '+' || *tptr == ' ')
	// {
	// }
}

int	sp_load(va_list vlist, t_flags *flags)
{

}

int	sp_type(const char c, t_flags *flags)
{
	if (c == 'c' || c == 's' || c == 'p' ||
		c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
	{
		flags->specifier = c;
		return (c);
	}
	return (0);
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
