#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	fl_sp_c(va_list vlist, t_flags *flags);
int	fl_sp_s(va_list vlist, t_flags *flags);
int	fl_sp_di(va_list vlist, t_flags *flags);
int	fl_sp_u(va_list vlist, t_flags *flags);
int	fl_sp_p(va_list vlist, t_flags *flags);
int	fl_sp_xX(va_list vlist, t_flags *flags);

int	fl_load(va_list vlist, t_flags *flags)
{
	if (flags->specifier == 'c')
		return (fl_sp_c(vlist, flags));
	else if (flags->specifier == 's')
		return (fl_sp_s(vlist, flags));
	else if (flags->specifier == 'd' || flags->specifier == 'i')
		return (fl_sp_di(vlist, flags));
	else if (flags->specifier == 'u')
		return (fl_sp_u(vlist, flags));
	else if (flags->specifier == 'x' || flags->specifier == 'X')
	    return (fl_sp_xX(vlist, flags));
	else if (flags->specifier == 'p')
		return (fl_sp_p(vlist, flags));
    return (0);
}

int	fl_sp_c(va_list vlist, t_flags *flags)
{
	char c;

	c = (char)va_arg(vlist, int);
	if (flags->width)
	{
		if (flags->left_align)
		{
			ft_putchar_fd(c, 1);
			ft_putnchar_fd(' ', flags->width - 1, 1);
		}
		else
		{
			ft_putnchar_fd(' ', flags->width - 1, 1);
			ft_putchar_fd(c, 1);
		}
		return (flags->width);
	}
	else
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	// if (flags->left_align || flags->width)
	// {
	// 	flags->buffer = malloc(flags->width + 1);
	// 	if (!flags->buffer)
	// 		return (0);
	// 	flags->buffer[flags->width] = '\0';
	// 	if (flags->left_align)
	// 	{
	// 		flags->buffer[0] = c;
	// 		ft_memset(flags->buffer + 1, ' ', flags->width - 1);
	// 	}
	// 	else
	// 	{
	// 		ft_memset(flags->buffer, ' ', flags->width - 1);
	// 		flags->buffer[flags->width] = c;
	// 	}
	// 	ft_putstr_fd(flags->buffer, 1);
	// 	free(flags->buffer);
	// 	return (flags->width);
	// }
	// ft_putstr_fd(&c, 1);
	// return (1);
}

int	fl_sp_s(va_list vlist, t_flags *flags)
{
	char	*s;
	int		s_len;

	s = va_arg(vlist, char *);
	if (!s)
	{
		if (flags->precision == -1 || flags->precision >= 6)
			s = "(null)";
		else
			s = "";
	}
	s_len = (int)ft_strlen(s);
	if (flags->precision >= 0 && flags->precision < s_len)
		s_len = flags->precision;
	if (flags->width > s_len)
	{
		if (flags->left_align)
		{
			ft_putnstr_fd(s, s_len, 1);
			ft_putnchar_fd(' ', flags->width - s_len, 1);
		}
		else
		{
			ft_putnchar_fd(' ', flags->width - s_len, 1);
			ft_putnstr_fd(s, s_len, 1);
		}
		return (flags->width);
	}
	else
	{
		ft_putnstr_fd(s, s_len, 1);
		return (s_len);
	}
	// if (flags->width > (int)s_len)
	// {
	// 	flags->buffer = malloc(flags->width + 1);
	// 	if (!flags->buffer)
	// 		return (0);
	// 	flags->buffer[flags->width] = '\0';
	// 	if (flags->left_align)
	// 	{
	// 		ft_memcpy(flags->buffer, s, s_len);
	// 		ft_memset(flags->buffer + s_len, ' ', flags->width - s_len);
	// 	}
	// 	else
	// 	{
	// 		ft_memset(flags->buffer, ' ', flags->width - s_len);
	// 		ft_memcpy(flags->buffer + (flags->width - s_len), s, s_len);
	// 	}
	// 	ft_putstr_fd(flags->buffer, 1);
	// 	free(flags->buffer);
	// 	return (flags->width);
	// }
	// ft_putnstr_fd(s, s_len, 1);
	// return ((int) s_len);
}

int	fl_sp_di(va_list vlist, t_flags *flags)
{
	int val;
	int n_len;
	int neg;
	int p_len;
	int n_size;

	val = va_arg(vlist, int);
	if (!val && !flags->precision)
	{
		if (flags->width)
		{
			ft_putnchar_fd(' ', flags->width, 1);
			return (flags->width);
		}
		return (0);
	}
	neg = 0;
	p_len = 0;
	if (val < 0)
	{
		neg = 1;
		if (val != -2147483648)
			val = -val;
	}
	n_len = ft_countdigits(val);
	if (flags->precision > n_len)
		p_len = flags->precision - n_len;
	flags->buffer = ft_itoa(val);
	if (!flags->buffer)
		return (0);
	n_size = n_len + p_len + (neg || flags->show_sign || flags->space);
	if (flags->width > n_size)
	{
		if (flags->left_align)
		{
			if (neg && val != -2147483648)
				ft_putchar_fd('-', 1);
			else if (flags->show_sign)
				ft_putchar_fd('+', 1);
			else if (flags->space)
				ft_putchar_fd(' ', 1);
			if (p_len)
				ft_putnchar_fd('0', p_len, 1);
			ft_putstr_fd(flags->buffer, 1);
			ft_putnchar_fd(' ', flags->width - n_size, 1);
		}
		else
		{
			if (flags->zero_pad)
				ft_putnchar_fd('0', flags->width - n_size, 1);
			else
				ft_putnchar_fd(' ', flags->width - n_size, 1);
			if (neg && val != -2147483648)
				ft_putchar_fd('-', 1);
			else if (flags->show_sign)
				ft_putchar_fd('+', 1);
			else if (flags->space)
				ft_putchar_fd(' ', 1);
			if (p_len)
				ft_putnchar_fd('0', p_len, 1);
			ft_putstr_fd(flags->buffer, 1);
		}
	}
	else
	{
		if (neg && val != -2147483648)
			ft_putchar_fd('-', 1);
		else if (flags->show_sign)
			ft_putchar_fd('+', 1);
		else if (flags->space)
			ft_putchar_fd(' ', 1);
		if (p_len)
			ft_putnchar_fd('0', p_len, 1);
		ft_putstr_fd(flags->buffer, 1);	
	}
	free(flags->buffer);
	if (flags->width > n_size)
		return (flags->width);
	return (n_size);
}

int	fl_sp_u(va_list vlist, t_flags *flags)
{
	unsigned int val;
	int n_len;
	int p_len;
	int n_size;

	val = va_arg(vlist, unsigned int);
	if (!val && !flags->precision)
	{
		if (flags->width)
		{
			ft_putnchar_fd(' ', flags->width, 1);
			return (flags->width);
		}
		return (0);
	}
	p_len = 0;
	n_len = ft_countdigits_u(val);
	if (flags->precision > n_len)
		p_len = flags->precision - n_len;
	flags->buffer = ft_itoa_u(val);
	if (!flags->buffer)
		return (0);
	n_size = n_len + p_len;
	if (flags->width > n_size)
	{
		if (flags->left_align)
		{
			if (p_len)
				ft_putnchar_fd('0', p_len, 1);
			ft_putstr_fd(flags->buffer, 1);
			ft_putnchar_fd(' ', flags->width - n_size, 1);
		}
		else
		{
			if (flags->zero_pad)
				ft_putnchar_fd('0', flags->width - n_size, 1);
			else
				ft_putnchar_fd(' ', flags->width - n_size, 1);
			if (p_len)
				ft_putnchar_fd('0', p_len, 1);
			ft_putstr_fd(flags->buffer, 1);
		}
	}
	else
	{
		if (p_len)
			ft_putnchar_fd('0', p_len, 1);
		ft_putstr_fd(flags->buffer, 1);	
	}
	free(flags->buffer);
	if (flags->width > n_size)
		return (flags->width);
	return (n_size);
}

int	fl_sp_p(va_list vlist, t_flags *flags)
{
	void	*ptr;
	int		size;
	int		pfix;

	ptr = va_arg(vlist, void *);
	if (!ptr)
	{
		flags->buffer = ft_strdup("(nil)");
		pfix = 0;
	}
	else
	{
		flags->buffer = ft_itoa_hex((unsigned long int)ptr);
		pfix = 2;
	}
	if (!flags->buffer)
		return (0);
	size = (int)ft_strlen(flags->buffer) + pfix;
	if (flags->width > size)
	{
		size = flags->width - size;
		if (flags->left_align)
		{
			if (pfix)
				ft_putstr_fd("0x", 1);
			ft_putstr_fd(flags->buffer, 1);
			ft_putnchar_fd(' ', size, 1);
		}
		else
		{
			ft_putnchar_fd(' ', size, 1);
			if (pfix)
				ft_putstr_fd("0x", 1);
			ft_putstr_fd(flags->buffer, 1);
		}
	}
	else
	{
		if (pfix)
			ft_putstr_fd("0x", 1);
		ft_putstr_fd(flags->buffer, 1);
	}
	free(flags->buffer);
	if (flags->width > size)
		return (flags->width);
	return (size);
}

int fl_sp_xX(va_list vlist, t_flags *flags)
{
	unsigned int	val;
	int				n_len;
	int				p_len;
	int				n_size;
	int				pfix;

	val = va_arg(vlist, unsigned int);
	if (!val && !flags->precision)
	{
		if (flags->width)
		{
			ft_putnchar_fd(' ', flags->width, 1);
			return (flags->width);
		}
		return (0);
	}
	n_len = ft_countdigits_hex(val);
	p_len = 0;
	pfix = 0;
	if (flags->precision > n_len)
		p_len = flags->precision - n_len;
	if (flags->hash_hex && val != 0)
		pfix = 2;
	n_size = n_len + p_len + pfix;
	flags->buffer = ft_itoa_hex(val);
	if (!flags->buffer)
		return (0);
	if (flags->specifier == 'X')
		ft_struppercase(flags->buffer);
	if (flags->width > n_size)
	{
		if (flags->left_align)
		{
			if (pfix && flags->specifier == 'x')
				ft_putstr_fd("0x", 1);
			else if (pfix && flags->specifier == 'X')
				ft_putstr_fd("0X", 1);
			if (p_len)
				ft_putnchar_fd('0', p_len, 1);
			ft_putstr_fd(flags->buffer, 1);
			ft_putnchar_fd(' ', flags->width - n_size, 1);
		}
		else
		{
			if (flags->zero_pad)
				ft_putnchar_fd('0', flags->width - n_size, 1);
			else
				ft_putnchar_fd(' ', flags->width - n_size, 1);
			if (pfix && flags->specifier == 'x')
				ft_putstr_fd("0x", 1);
			else if (pfix && flags->specifier == 'X')
				ft_putstr_fd("0X", 1);
			if (p_len)
				ft_putnchar_fd('0', p_len, 1);
			ft_putstr_fd(flags->buffer, 1);
		}
	}
	else
	{
		if (pfix && val != 0 && flags->specifier == 'x')
			ft_putstr_fd("0x", 1);
		else if (pfix && val != 0 && flags->specifier == 'X')
			ft_putstr_fd("0X", 1);
		if (p_len)
			ft_putnchar_fd('0', p_len, 1);
		ft_putstr_fd(flags->buffer, 1);
	}
	free(flags->buffer);
	if (flags->width > n_size)
		return (flags->width);
	return (n_size);
}
