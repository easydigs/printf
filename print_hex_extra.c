#include "main.h"

/**
 * print_hex_extra - prints an hexedecimal number.
 * @num: arguments
 *i added this comment so i can confirm I did something and review the content
 * Return: counter
 */

int print_hex_extra(unsigned long int num)
{
	long int i;
	long int *array;
	long int counter = 0;
	unsigned long int t = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

	for (i = 0; i < counter; i++)
	{
		array[i] = t % 16;
		t = t / 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}
