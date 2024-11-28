#include <stdio.h>
#include "ft_printf.h" // Assuming ft_printf is declared here

int main(void)
{
    int ret_original, ret_custom;

    printf("=== Comparing ft_printf vs printf for Escape Characters and %% ===\n");

    // Basic Escape Character Tests
    printf("\nBasic Escape Character Tests:\n");
    
    ret_original = printf("Original: 'Hello\\nWorld'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Hello\\nWorld'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Tab\\tSpace'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Tab\\tSpace'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Carriage Return\\rCR'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Carriage Return\\rCR'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Backspace\\bB'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Backspace\\bB'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Form Feed\\fForm'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Form Feed\\fForm'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Vertical Tab\\vVT'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Vertical Tab\\vVT'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Alert\\aBell'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Alert\\aBell'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Single Quote\\''\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Single Quote\\''\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Double Quote\\\"'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Double Quote\\\"'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Backslash\\\\'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Backslash\\\\'\n");
    printf("Return: %d\n", ret_custom);

    // Literal Percent Tests
    printf("\nLiteral Percent Tests:\n");

    ret_original = printf("Original: '%%'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%%'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Hello %% World'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Hello %% World'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: '%% %% %%'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   '%% %% %%'\n");
    printf("Return: %d\n", ret_custom);

    // Mixed Tests (Escape Characters and Literal Percent)
    printf("\nMixed Tests:\n");

    ret_original = printf("Original: 'Newline\\n and Percent %%'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Newline\\n and Percent %%'\n");
    printf("Return: %d\n", ret_custom);

    ret_original = printf("Original: 'Tab\\t and Percent %%'\n");
    printf("Return: %d\n", ret_original);
    ret_custom = ft_printf("Custom:   'Tab\\t and Percent %%'\n");
    printf("Return: %d\n", ret_custom);

    return 0;
}

