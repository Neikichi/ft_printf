#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret_original, ret_custom;
    const char *str = "Hello, World!";
    const char *empty_str = "";
    const char *null_str = NULL;

    printf("=== Comparing ft_printf vs printf for %%s ===\n");

    // Basic Tests
    printf("\nBasic Tests:\n");
    ret_original = printf("Original: '%s'\n", str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%s'\n", str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%s '\n", "");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%s '\n", "");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%s'\n", null_str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%s'\n", null_str);
    printf("Return: %d\n", ret_custom);

    // Width Tests
    printf("\nWidth Tests:\n");
    ret_original = printf("Original: '%20s'\n", str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%20s'\n", str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-20s'\n", str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-20s'\n", str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%20s'\n", empty_str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%20s'\n", empty_str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%20s'\n", null_str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%20s'\n", null_str);
    printf("Return: %d\n", ret_custom);

    // Precision Tests
    printf("\nPrecision Tests:\n");
    ret_original = printf("Original: '%.5s'\n", str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.5s'\n", str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.0s'\n", str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.0s'\n", str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.0s'\n", empty_str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.0s'\n", empty_str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.5s'\n", null_str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.5s'\n", null_str);
    printf("Return: %d\n", ret_custom);

    // Width + Precision Combined
    printf("\nWidth + Precision Combined:\n");
    ret_original = printf("Original: '%20.5s'\n", str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%20.5s'\n", str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-20.5s'\n", str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-20.5s'\n", str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%20.0s'\n", str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%20.0s'\n", str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%20.5s'\n", null_str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%20.5s'\n", null_str);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-20.5s'\n", null_str);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-20.5s'\n", null_str);
    printf("Return: %d\n", ret_custom);

	// Tester check
    printf("\nTester check:\n");
    ret_original = printf("Original: 'aa%.s'\n", "");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'aa%.s'\n", "");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.s '\n", "");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.s '\n", "");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%.s'\n", "-");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%.s'\n", "-");
    printf("Return: %d\n", ret_custom);

    return 0;
}

