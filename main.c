#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    /* Commenting out the lines using the %r specifier as it is not standard */
    /* _printf("Unknown:[%r]\n"); */
    /* printf("Unknown:[%r]\n"); */

    return (0);
}

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++;
            switch (*format)
            {
            case 'd':
            case 'i':
                count += printf("%d", va_arg(args, int));
                break;
            case 'u':
                count += printf("%u", va_arg(args, unsigned int));
                break;
            case 'o':
                count += printf("%o", va_arg(args, unsigned int));
                break;
            case 'x':
                count += printf("%x", va_arg(args, unsigned int));
                break;
            case 'X':
                count += printf("%X", va_arg(args, unsigned int));
                break;
            case 'c':
                count += printf("%c", va_arg(args, int));
                break;
            case 's':
                count += printf("%s", va_arg(args, char *));
                break;
            case 'p':
                count += printf("%p", va_arg(args, void *));
                break;
            case '%':
                count += printf("%%");
                break;
            /* Add more cases for other format specifiers as needed */
            default:
                /* Handle unknown format specifiers */
                fprintf(stderr, "Unknown format specifier: %%%c\n", *format);
                break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
