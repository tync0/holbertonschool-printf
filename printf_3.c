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

	va_start(ptr, format);
	if (format == NULL)
		return (size);
	while (format[i])
	{
		if (format[i] != '%')
		{
			size += write(1, format[i], 1);
		}
		else
		{
			if (format[i + 1] && format[i + 1] == 'c')
			{
				size += write(1, va_arg(ptr, int), 1);
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
				size += write(1, format[i], 1);
			}
		}
		i++;
	}
	va_end(ptr);

	return (size);
}
