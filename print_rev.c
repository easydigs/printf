#include "main.h"

/**
 * print_revs - function that print a string in reverse
 * @args: type struct va_arg where is allocated printf arguments
 * i added this comment so i can confirm I did something and review the content
 * Return: the string
 */
int print_revs(va_list args)
{

	char *str = va_arg(args, char*);
	int i;
	int k = 0;

	if (str == NULL)
		str = "(null)";
	while (str[k] != '\0')
		k++;
	for (i = k - 1; i >= 0; i--)
		_putchar(str[i]);
	return (k);
}
