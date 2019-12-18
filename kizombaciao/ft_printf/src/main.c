//#include "../libft/libft.h"
//#include <locale.h> // ???
//#include <stdio.h>

#include "../inc/ft_printf.h"

int main()
{
    int i;

//    setlocale(LC_ALL, "");
    ft_printf("Hello World!  %d\n", 42);
/*
    ft_printf("%s", "This is ");
    ft_printf("%.*s\n", 9, "ft_printf and ft_dprintf");
    ft_printf("%d\n", 123);
    ft_printf("%05d\n", 42);
    ft_printf("%+09d\n", 42);
    ft_printf("%u\n", UINT_MAX);
    ft_printf("%#b\n", 256);
    ft_printf("%#o\n", 1039);
    ft_printf("%#X\n", 16417188);
    ft_printf("%p\n", &i);
    ft_printf("%C %C %C\n", L'ä', L'ö', L'ü');
    ft_printf("%S\n", L"🤗 💯 🌍 🚀 🔴 ");
*/
    return (0);
}

// QUESTIONS:
// extern ???
// inline ???


// const char *ptr
// https://www.geeksforgeeks.org/difference-const-char-p-char-const-p-const-char-const-p/
// I can't change the content but I can change the address.

// unsigned char
// https://www.quora.com/What-is-signed-char-and-unsigned-char-exactly
// just means that unsigned char takes a different set of ascii table from signed char
// unsigned goes from 0 to 255 and signed goes from -128 to 127.

// https://github.com/fpetras/ft_printf

// setlocale:
// https://www.tutorialspoint.com/c_standard_library/c_function_setlocale
