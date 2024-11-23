/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:44:16 by vlow              #+#    #+#             */
/*   Updated: 2024/11/23 17:14:27 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flags {
	int		left_align;
	int		zero_pad;
	int		hash_hex;
	int		show_sign;
	int		space;
	int		width;
	int		precision;
	char	specifier;
	char	*buffer;
}	t_flags;

#endif
