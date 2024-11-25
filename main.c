#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"



int main(void)
{
	char *str = "world";
	int n = 123;

	int i = ft_printf("hello [%-05.05s] and [%-10.05d] and [%.155d] and [%#+d].\n", str, n, 11, 111);
	printf("%d", i);


	return (0);
}

