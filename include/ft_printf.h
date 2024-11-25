/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:44:16 by vlow              #+#    #+#             */
/*   Updated: 2024/11/25 22:17:51 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
typedef struct s_flags {
	int		left_align; // store after the value
	int		zero_pad; // store before the value
	int		hash_hex; // flag 1 for 0x, 2 for 0X, 3 for 0.
	int		show_sign; // 1 for sign or 0 for no
	int		space; // store before the value
	int		width; // might not needed
	int		precision; // store limits of char
	char	specifier; // store sp type
	char	*buffer;
}	t_flags;

int	ft_printf(const char *format, ...);
int	sp_c(va_list vlist, t_flags *flags);

//flags
int		fl_set(const char *c, t_flags *flags);
void	fl_set_precision(const char **c, t_flags *flags);
void	fl_set_width(const char **c, t_flags *flags);
t_flags	fl_init(void);

// to add to libft
int		ft_countdigits(long int n);

#endif
