#include "bish.h"

/**
 * _strlen - returns the len of a string
 * @str: str we are getting len of
 *
 * Return: length of str
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
