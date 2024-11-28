#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
// #include "ft_printf.h"

int main(void)
{
    int ret_original, ret_custom;
    int x = 42;

    printf("=== Comprehensive Testing %%p with ft_printf ===\n");

    // Basic Tests
    printf("\nBasic Tests:\n");
    ret_original = printf("Original: '%p'\n", &x);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%p'\n", &x);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%p'\n", NULL);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%p'\n", NULL);
    printf("Return: %d\n", ret_custom);

    // Width Tests
    printf("\nWidth Tests:\n");
    ret_original = printf("Original: '%20p'\n", &x);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%20p'\n", &x);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%5p'\n", NULL);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%5p'\n", NULL);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%30p'\n", (void *)ULONG_MAX);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%30p'\n", (void *)ULONG_MAX);
    printf("Return: %d\n", ret_custom);

    // Left Alignment Tests
    printf("\nLeft Alignment Tests:\n");
    ret_original = printf("Original: '%-20p'\n", &x);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-20p'\n", &x);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-5p'\n", NULL);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-5p'\n", NULL);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-30p'\n", (void *)ULONG_MAX);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-30p'\n", (void *)ULONG_MAX);
    printf("Return: %d\n", ret_custom);

    // Edge Cases
    printf("\nEdge Cases:\n");
    ret_original = printf("Original: '%p'\n", (void *)0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%p'\n", (void *)0);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%p'\n", (void *)-1);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%p'\n", (void *)-1);
    printf("Return: %d\n", ret_custom);

	printf("\n%p\n", &ret_original);
	ft_printf("\n%p\n", &ret_original);
	printf("\n==%s==\n", ft_itoa_hex((unsigned long int)&ret_original));
    return 0;
}

