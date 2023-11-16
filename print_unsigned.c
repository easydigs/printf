#include "main.h"

/**
 * print_unsigned - prints integer
 * @args: argument to print
 *
 * Return: integer
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, last = n % 10, digit, e = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			e = e * 10;
			num = num / 10;
		}
		num = n;
		while (e > 0)
		{
			digit = num / e;
			_putchar(digit + '0');
			num = num - (digit * e);
			e = e / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}
