#include "bish.h"
#include <math.h>

/**
 * print_number - prints a number
 * @n: variable containing an integer value
 *
 * Return: count (int)
 */

int print_number(int n)
{
	int m = 1, num = n, count = 0;

	while (num / 10)
	{
		num /= 10;
		m *= 10;
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
	}
	while (m > 0)
	{
		num = n / m;
		m /= 10;
		if (n < 0)
		{
			_putchar(num % 10 * -1 + '0');
			count++;
		}
		else
		{
			_putchar(num % 10 + '0');
			count++;
		}
	}
	return (count);
}
