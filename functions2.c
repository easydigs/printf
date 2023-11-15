#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List of arguments
 * @output_buffer: Buffer array for print handling
 * @format_flags: Active formatting flags
 * @field_width: Width specifier
 * @precision: Precision specifier
 * @data_size: Size specifier
 * Return: Number of characters printed.
 */
int print_pointer(va_list args, char output_buffer[],
    int format_flags, int field_width, int precision, int data_size)
{
    char extra_char = 0, padding_char = ' ';
    int buffer_index = BUFF_SIZE - 2, length = 2, padding_start = 1; /* length=2, for '0x' */
    unsigned long address_value;
    char hex_map[] = "0123456789abcdef";
    void *address = va_arg(args, void *);

    UNUSED(field_width);
    UNUSED(data_size);

    if (address == NULL)
        return write(1, "(nil)", 5);

    output_buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(precision);

    address_value = (unsigned long)address;

    while (address_value > 0)
    {
        output_buffer[buffer_index--] = hex_map[address_value % 16];
        address_value /= 16;
        length++;
    }

    if ((format_flags & F_ZERO) && !(format_flags & F_MINUS))
        padding_char = '0';

    if (format_flags & F_PLUS)
        extra_char = '+', length++;
    else if (format_flags & F_SPACE)
        extra_char = ' ', length++;

    buffer_index++;

    return write_pointer(output_buffer, buffer_index, length,
        field_width, format_flags, padding_char, extra_char, padding_start);
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ASCII codes in hexadecimal of non-printable chars
 * @args: List of arguments
 * @output_buffer: Buffer array for print handling
 * @format_flags: Active formatting flags
 * @field_width: Width specifier
 * @precision: Precision specifier
 * @data_size: Size specifier
 * Return: Number of characters printed.
 */
int print_non_printable(va_list args, char output_buffer[],
    int format_flags, int field_width, int precision, int data_size)
{
    int i = 0, offset = 0;
    char *str = va_arg(args, char *);

    UNUSED(format_flags);
    UNUSED(field_width);
    UNUSED(precision);
    UNUSED(data_size);

    if (str == NULL)
        return write(1, "(null)", 6);

    while (str[i] != '\0')
    {
        if (is_printable(str[i]))
            output_buffer[i + offset] = str[i];
        else
            offset += append_hex_code(str[i], output_buffer, i + offset);

        i++;
    }

    output_buffer[i + offset] = '\0';

    return write(1, output_buffer, i + offset);
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @args: List of arguments
 * @output_buffer: Buffer array for print handling
 * @format_flags: Active formatting flags
 * @field_width: Width specifier
 * @precision: Precision specifier
 * @data_size: Size specifier
 * Return: Number of characters printed.
 */
int print_reverse(va_list args, char output_buffer[],
    int format_flags, int field_width, int precision, int data_size)
{
    char *str;
    int i, count = 0;

    UNUSED(output_buffer);
    UNUSED(format_flags);
    UNUSED(field_width);
    UNUSED(data_size);

    str = va_arg(args, char *);

    if (str == NULL)
    {
        UNUSED(precision);
        str = ")Null(";
    }

    for (i = 0; str[i]; i++)
        ;

    for (i = i - 1; i >= 0; i--)
    {
        char character = str[i];
        write(1, &character, 1);
        count++;
    }

    return count;
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in ROT13.
 * @args: List of arguments
 * @output_buffer: Buffer array for print handling
 * @format_flags: Active formatting flags
 * @field_width: Width specifier
 * @precision: Precision specifier
 * @data_size: Size specifier
 * Return: Number of characters printed.
 */
int print_rot13string(va_list args, char output_buffer[],
    int format_flags, int field_width, int precision, int data_size)
{
    char x;
    char *str;
    unsigned int i, j;
    int count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(args, char *);

    UNUSED(output_buffer);
    UNUSED(format_flags);
    UNUSED(field_width);
    UNUSED(precision);
    UNUSED(data_size);

    if (str == NULL)
        str = "(AHYY)";

    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                x = out[j];
                write(1, &x, 1);
                count++;
                break;
            }
        }
        if (!in[j])
        {
            x = str[i];
            write(1, &x, 1);
            count++;
        }
    }

    return count;
}
