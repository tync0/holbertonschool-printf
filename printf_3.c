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
		exit(98);
	while (format[i])
	{
		if (format[i] != '%')
		{
			size += write(1, format + i, 1);
		}
		else
		{
			if (format[i + 1] && format[i + 1] == 'c')
			{
				s = va_arg(ptr, int);
				size += write(1, &s, 1);
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
			else if (format[i + 1] && format[i + 1] == '%')
			{
				size += write(1, "%", 1);
				i++;
			}
		}
		i++;
	}
	va_end(ptr);

	return (size);
}
