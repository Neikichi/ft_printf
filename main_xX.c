#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int ret_original, ret_custom;
    unsigned int val = 42;

    printf("=== Comparing ft_printf vs printf for %%x and %%X ===\n");

    // Basic Tests
    printf("\nBasic Tests:\n");
    ret_original = printf("Original: '%x'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%x'\n", val);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%X'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%X'\n", val);
    printf("Return: %d\n", ret_custom);

    // Width Tests
    printf("\nWidth Tests:\n");
    ret_original = printf("Original: '%10x'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%10x'\n", val);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-10x'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-10x'\n", val);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%10X'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%10X'\n", val);
    printf("Return: %d\n", ret_custom);

    // Precision Tests
    printf("\nPrecision Tests:\n");
    ret_original = printf("Original: '%.5x'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.5x'\n", val);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.0x'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.0x'\n", 0);
    printf("Return: %d\n", ret_custom);

    // Width + Precision Combined
    printf("\nWidth + Precision Combined:\n");
    ret_original = printf("Original: '%10.5x'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%10.5x'\n", val);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-10.5x'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-10.5x'\n", val);
    printf("Return: %d\n", ret_custom);

    // Flags Tests (`#`, `0`)
    printf("\nFlags Tests:\n");
    ret_original = printf("Original: '%#x'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%#x'\n", val);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%#X'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%#X'\n", val);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%#10x'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%#10x'\n", val);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%010x'\n", val);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%010x'\n", val);
    printf("Return: %d\n", ret_custom);

    // Edge Cases
    printf("\nEdge Cases:\n");
    ret_original = printf("Original: '%x'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%x'\n", 0);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%#x'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%#x'\n", 0);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%x'\n", UINT_MAX);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%x'\n", UINT_MAX);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%10.0x'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%10.0x'\n", 0);
    printf("Return: %d\n", ret_custom);

    return 0;
}

