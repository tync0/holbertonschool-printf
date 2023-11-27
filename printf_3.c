#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

/**
 * _printf - produces output according to a format
 *
 * @format: var
 *
 * Return: Always 0.
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	int i = 0, size = 0;
	char *str;
	char s;

	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			size++;
		}
		else
		{
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(ptr, char));
				size++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				str = va_arg(ptr, char *);
				size += write(1, str, strlen(str));
				i++;
			}
		}
		i++;
	}

	return (size);
}
