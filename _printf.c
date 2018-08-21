#include "bish.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
  * _printf - similar to printf from stdio.h
  * @format: character string
  * Return: number of string printed
  */

int _printf(const char *format, ...)
{
	char *var;
	int num;
	int i, len, count = 0;
	va_list val;

	if (format == NULL)
		return (-1);
	va_start(val, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(val, int));
					count++;
					break;
				case 's':
					var = va_arg(val, char*);
					if (var == NULL)
					{
						var = "(null)";
						_puts(var);
						count += _strlen(var);
						break;
					}
					len = _strlen(var);
					if (var[len] != 0)
						return (-1);
					_puts(var);
					count += _strlen(var);
					break;
				case '%':
					_putchar(format[i]);
					count++;
					break;
				case 'i':
				case 'd':
					count += print_number(va_arg(val, int));
					break;
				case ' ':
					return (-1);
				case '\0':
					return (-1);
				case 'b':
					num = va_arg(val, int);
					if (num < 0)
						return (-1);
					count += binary(num);
					break;
				case 'r':
					var = va_arg(val, char *);
					if (var == NULL)
					{
						var = "(null)";
						_puts(var);
						count += print_rev(var);
						break;
					}
					count += print_rev(var);
					break;
				case 'R':
					var = va_arg(val, char *);
					if (var == NULL)
					{
						var = "(null)";
						_puts(var);
						count += rot13(var);
						break;
					}
					count += rot13(var);
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(val);
	return (count);
}
