#include "main.h"

/**
 * print_pointer - prints an hex number
 * @val: arguments
 * i added this comment so i can confirm I did something and review the content
 * Return: counter
 */

int print_pointer(va_list val)
{
	void *ptr;
	char *s = "(nil)";
	long int h;
	int y;
	int i;

	ptr = va_arg(val, void*);
	if (ptr == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	h = (unsigned long int)ptr;
	_putchar('0');
	_putchar('h');
	y = print_hex_extra(h);
	return (y + 2);
}
