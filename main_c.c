#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret_original, ret_custom;
    char c = 'A';
    char null_char = '\0';

    printf("=== Comparing ft_printf vs printf for %%c ===\n");

    // Basic Tests
    printf("\nBasic Tests:\n");
    ret_original = printf("Original: '%c'\n", c);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%c'\n", c);
    printf("Return: %d\n", ret_custom);

    // Null Character Test
    printf("\nNull Character Test:\n");
    ret_original = printf("Original: '%c'\n", null_char);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%c'\n", null_char);
    printf("Return: %d\n", ret_custom);

    // Width Tests
    printf("\nWidth Tests:\n");
    ret_original = printf("Original: '%5c'\n", c);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%5c'\n", c);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%-5c'\n", c);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-5c'\n", c);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%5c'\n", null_char);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%5c'\n", null_char);
    printf("Return: %d\n", ret_custom);

    // Flags Tests (`-`)
    printf("\nFlags Tests:\n");
    ret_original = printf("Original: '%-c'\n", c);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%-c'\n", c);
    printf("Return: %d\n", ret_custom);

    // Edge Cases
    printf("\nEdge Cases:\n");
    ret_original = printf("Original: '%c'\n", 0);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%c'\n", 0);
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%10c'\n", c);
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%10c'\n", c);
    printf("Return: %d\n", ret_custom);

    return 0;
}

