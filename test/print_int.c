#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

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
	char s[80];
	int x;

	va_start(ptr, format);

	if (format == NULL)
		exit(98);
	while (format[i])
	{
		if (format[i] != '%')
		{
			size += write(1, format + i, 1);
		}
		else
		{
			if (format[i + 1] && (format[i + 1] == 'd' || 
					     format[i + 1] == 'i'))
			{
				x = va_arg(ptr, int);
				sprintf(s, "%d", x);
				size += write(1, s, strlen(s));
				i++;
			}
			else if (format[i + 1])
			{
				size += write(1, "%", 1);
				if (format[i + 1] == '%')
					i++;
			}
		}
		i++;
	}
	va_end(ptr);
	return (size == 0 ? -1 : size);
}
