#include "main.h"

/**
 * print_i - function that prints an integer
 * @args: argument to print
 *i added this comment so i can confirm I did something and review the content
 * Return: integer
 */

int print_i(va_list args)
{
	int n = va_arg(args, int);
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
