#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

/**
 * _printf - produces output according to a format
 *
 * @format: varrr
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
				_putchar(va_arg(ptr, char));
				size++;
				i++;
			}
			else if (format[i + 1] && format[i + 1] == 's')
			{
				str = va_arg(ptr, char *);
				if (str == NULL)
					size += write(1, "(null)", strlen("(null)"));
				else
					size += write(1, str, strlen(str));
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
