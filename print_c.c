#include "main.h"

/**
 * print_c - prints a character
 * @val: arguments
 * i added this comment so i can confirm I did something and review the content
 * Return: integer
 */

int print_c(va_list val)
{
	char c;

	c = va_arg(val, int);
	_putchar(c);
	return (1);
}
