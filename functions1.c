#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Include the necessary header for the 'write' function

#define BUFF_SIZE 100
#define F_HASH 1  // Assuming F_HASH is a flag

// Define UNUSED macro if not defined
#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

// Function prototypes
unsigned long int convert_size_unsgnd(unsigned long int n, int size);
int write_unsgnd(int is_negative, int i, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

/************************* PRINT UNSIGNED NUMBER *************************/
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return write_unsgnd(0, i, buffer, flags, width, precision, size);
}

/************* PRINT UNSIGNED NUMBER IN OCTAL ****************/
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & F_HASH && init_num != 0)
        buffer[i--] = '0';

    i++;

    return write_unsgnd(0, i, buffer, flags, width, precision, size);
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size);
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size);
}
