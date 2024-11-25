/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:45:26 by vlow              #+#    #+#             */
/*   Updated: 2024/11/25 22:21:26 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

// int	ft_sp_load(va_list vlist, t_flags *flags);
int		sp_fl(const char **fptr);
void	print_flags(t_flags *flags);

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
			count += sp_fl(&fptr);
			fptr++;
		}
		if (*fptr == '\\')
		{
			// fptr++;
			// count += bs_esc(*fptr);
			// fptr++;
		}
		write(1, &*fptr, 1);
		fptr++;
	}
	return (count);
}

int	sp_fl(const char **fptr)
{
	// const char	*tptr;
	t_flags flags;

	flags = fl_init();
	if (!fl_set(*fptr, &flags))
		return (0);
	print_flags(&flags);
	return (0);
	// return (ft_sp_load(vlist, &flags));
}

// int	ft_sp_load(va_list vlist, t_flags *flags)
// {
// 	if (flags->specifier == 'c')
// 		return (sp_c(vlist, flags));
// 	return (0);
// }


void print_flags(t_flags *flags)
{
    printf("Flags:\n");
    printf("  left_align  : %d\n", flags->left_align);
    printf("  zero_pad    : %d\n", flags->zero_pad);
    printf("  hash_hex    : %d\n", flags->hash_hex);
    printf("  show_sign   : %d\n", flags->show_sign);
    printf("  space       : %d\n", flags->space);
    printf("  width       : %d\n", flags->width);
    printf("  precision   : %d\n", flags->precision);
    printf("  specifier   : %c\n", flags->specifier ? flags->specifier : '-');
}
//
// int main(void)
// {
// 	char *str = "world";
// 	int n = 123;
//
// 	int i = ft_printf("hello [%s] and [%d].\n", str, n);
// 	printf("%d", i);
//
//
// 	return (0);
// }
