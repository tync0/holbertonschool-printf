#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

/**
 * print_str - prints string
 * @str: string to be printed
 *
 * Return: number of printed chars
 */

int print_str(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", strlen("(null)")));
	else
		return (write(1, str, strlen(str)));
}


/**
 * _printf - produces output according to a format
 *
 * @format: varrr
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	int i = 0, size = 0; 
	int c;

	va_start(ptr, format);

	if (format == NULL)
		return (size);

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			size++;
		}
		else
		{
			if (format[i + 1] && format[i + 1] == 'c')
			{
				c = va_arg(ptr, int);
				size += write(1, &c, 1);
				i++;
			}
			else if (format[i + 1] && format[i + 1] == 's')
			{
				size += print_str(va_arg(ptr, char *));
				i++;
			}
			else if (format[i + 1])
			{
				_putchar(format[i]);
				size++;
			}
		}
		i++;
	}
	va_end(ptr);
	return (size);
}
