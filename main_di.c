#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ret_original, ret_custom;

    printf("=== Comparing ft_printf vs printf ===\n");

    // Basic Tests
    printf("\nBasic Tests:\n");
    ret_original = printf("Original: '%d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%d'\n", -42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%d'\n", -42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%d'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%d'\n", 0);
    printf("Return: %d\n", ret_custom);

    // Width Tests
    printf("\nWidth Tests:\n");
    ret_original = printf("Original: '%5d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%5d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-5d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-5d'\n", 42);
    printf("Return: %d\n", ret_custom);

    // Precision Tests
    printf("\nPrecision Tests:\n");
    ret_original = printf("Original: '%.5d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.5d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.0d'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.0d'\n", 0);
    printf("Return: %d\n", ret_custom);

    // Width + Precision Combined
    printf("\nWidth + Precision Combined:\n");
    ret_original = printf("Original: '%8.5d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%8.5d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-8.5d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-8.5d'\n", 42);
    printf("Return: %d\n", ret_custom);

    // Flags Tests
    printf("\nFlags Tests:\n");
    ret_original = printf("Original: '%+d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%+d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '% d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '% d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%05d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%05d'\n", 42);
    printf("Return: %d\n", ret_custom);

    // Edge Cases
    printf("\nEdge Cases:\n");
    ret_original = printf("Original: '%d'\n", INT_MAX);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%d'\n", INT_MAX);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%d'\n", INT_MIN);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%d'\n", INT_MIN);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%10.5d'\n", -42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%10.5d'\n", -42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%010d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%010d'\n", 42);
    printf("Return: %d\n", ret_custom);

    // Additional Edge Cases and Combinations
    printf("\nAdditional Edge Cases and Combinations:\n");
    ret_original = printf("Original: '%50d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%50d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.50d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.50d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%5.8d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%5.8d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-05d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-05d'\n", 42);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%+ d'\n", 42);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%+ d'\n", 42);
    printf("Return: %d\n", ret_custom);

	//tester case
    printf("\nTester edge cases:\n");

    ret_original = printf("Original: '%.11d'\n", INT_MIN);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.11d'\n", INT_MIN);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.12d'\n", INT_MIN);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.12d'\n", INT_MIN);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.13d'\n", INT_MIN);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.13d'\n", INT_MIN);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.14d'\n", INT_MIN);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.14d'\n", INT_MIN);
    printf("Return: %d\n", ret_custom);


    return 0;
}

