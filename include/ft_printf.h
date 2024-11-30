/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:44:16 by vlow              #+#    #+#             */
/*   Updated: 2024/11/30 20:38:07 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

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

int		ft_printf(const char *format, ...);
int		bs_esc(const char *fptr);

//flags
int		fl_set(const char **c, t_flags *flags);
t_flags	fl_init(void);
int		fl_load(va_list vlist, t_flags *flags);

// flags and sp
int		fl_sp_c(va_list vlist, t_flags *flags);
int		fl_sp_s(va_list vlist, t_flags *flags);
int		fl_sp_di(va_list vlist, t_flags *flags);
int		fl_sp_u(va_list vlist, t_flags *flags);
int		fl_sp_p(va_list vlist, t_flags *flags);
int		fl_sp_x(va_list vlist, t_flags *flags);

// to add to libft
int		ft_countdigits(long int n);
void	ft_putnstr_fd(char *s, int n, int fd);
void	ft_putnchar_fd(char c, int n, int fd);
int		ft_countdigits_u(unsigned long int n);
char	*ft_itoa_u(unsigned long int n);
char	*ft_itoa_hex(unsigned long int n);
int		ft_countdigits_hex(unsigned long int n);
int		ft_isupper(int c);
int		ft_islower(int c);
void	ft_strlowercase(char *str);
void	ft_struppercase(char *str);

#endif
