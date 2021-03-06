#include "bish.h"

/**
  * _strcmp - compares two strings
  * @s1: first operand (string)
  * @s2: second operand (string)
  *
  * Return: difference between s1 and s2
  */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);

	return (s1[i] - s2[i]);
}
