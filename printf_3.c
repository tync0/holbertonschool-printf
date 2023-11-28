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
	char s, s1[80];
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
			if (format[i + 1] && format[i + 1] == 'c')
			{
				s = va_arg(ptr, int);
				size += write(1, &s, 1);
				i++;
			}
			else if (format[i + 1] && format[i + 1] == 's')
			{
				size += print_str(va_arg(ptr, char *));
				i++;
			}
			else if (format[i + 1] && (format[i + 1] == 'd' ||
						format[i + 1] == 'i'))
			{
				x = va_arg(ptr, int);
				sprintf(s1, "%d", x);
				size += write(1, s1, strlen(s1));
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
