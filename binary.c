#include "bish.h"
#include <stdlib.h>

/**
  * binary - converts decimal to binary
  * @n: decimal number
  * Return: number of characters printed
  */

int binary(unsigned int n)
{
	int i, j, count = 0;
	char *arr;

	if (n > 0)
	{
		for (j = n, i = 0; j > 0; i++)
		{
			j %= 2;
			j /= 2;
		}

		arr = malloc(i - 1);

		for (i = 0; n > 0; i++)
		{
			arr[i] = n % 2;
			n /= 2;
		}
		for (i--; i >= 0; i--)
		{
			_putchar(arr[i] + '0');
			count++;
		}
	}
	else
	{
		_putchar('0');
		count++;
	}

	return (count);
}
