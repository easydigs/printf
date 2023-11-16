
#include "main.h"

/**
 * print_HEX_extra - prints an hexedecimal number.
 * @num: number to print
 *i added this comment so i can confirm I did something and review the content
 * Return: counter
 */

int print_HEX_extra(unsigned int num)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int t = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = t % 16;
		t /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}
