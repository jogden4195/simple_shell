#include "bish.h"
#include <stdio.h>

/**
  * *rot13 - encodes a string using rot13
  * @s: pointer to a string
  * Return: result after encription
  */

int rot13(char *s)
{
	int scan, i, count = 0;
	char norm[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (scan = 0; s[scan] != '\0'; scan++)
	{
		for (i = 0; norm[i] != 0; i++)
			if (s[scan] == norm[i])
			{
				_putchar(rot[i]);
				count++;
			}
	}
	return (count);
}
