#include "libft.h"
#include "ft_printf.h"

int	bs_esc(const char *fptr)
{
	if (*fptr == 'n' )
		ft_putchar_fd('\n', 1);
	else if (*fptr == 't')
		ft_putchar_fd('\t', 1);
	else if (*fptr == 'r')
		ft_putchar_fd('\r', 1);
	else if (*fptr == 'b')
		ft_putchar_fd('\b', 1);
	else if (*fptr == 'f')
		ft_putchar_fd('\f', 1);
	else if (*fptr == 'v')
		ft_putchar_fd('\v', 1);
	else if (*fptr == 'a')
		ft_putchar_fd('\a', 1);
	else if (*fptr == '\\')
		ft_putchar_fd('\\', 1);
	else if (*fptr == '\'')
		ft_putchar_fd('\'', 1);
	else if (*fptr == '\"')
		ft_putchar_fd('\"', 1);
	else if (*fptr == '?')
		ft_putchar_fd('?', 1);
	else
	{
		ft_putchar_fd('\\', 1);
		ft_putchar_fd(*fptr, 1);
		return (2);
	}
	return (1);
}
