#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ret_original, ret_custom;

    printf("=== Comparing ft_printf vs printf for %%u ===\n");

    // Basic Tests
    printf("\nBasic Tests:\n");
    ret_original = printf("Original: '%u'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%u'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%u'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%u'\n", 0);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%u'\n", UINT_MAX);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%u'\n", UINT_MAX);
    printf("Return: %d\n", ret_custom);

    // Width Tests
    printf("\nWidth Tests:\n");
    ret_original = printf("Original: '%10u'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%10u'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-10u'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-10u'\n", 42);
    printf("Return: %d\n", ret_custom);

    // Precision Tests
    printf("\nPrecision Tests:\n");
    ret_original = printf("Original: '%.5u'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.5u'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.0u'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.0u'\n", 0);
    printf("Return: %d\n", ret_custom);

    // Width + Precision Combined
    printf("\nWidth + Precision Combined:\n");
    ret_original = printf("Original: '%10.5u'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%10.5u'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-10.5u'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-10.5u'\n", 42);
    printf("Return: %d\n", ret_custom);

    // Flags Tests
    printf("\nFlags Tests:\n");
    ret_original = printf("Original: '%05u'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%05u'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%07.5u'\n", 423211);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%07.5u'\n", 423211);
    printf("Return: %d\n", ret_custom);

    // Edge Cases
    printf("\nEdge Cases:\n");
    ret_original = printf("Original: '%u'\n", UINT_MAX);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%u'\n", UINT_MAX);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%10.5u'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%10.5u'\n", 0);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%010u'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%010u'\n", 42);
    printf("Return: %d\n", ret_custom);

    return 0;
}


