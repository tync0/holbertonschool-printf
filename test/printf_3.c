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
<<<<<<< HEAD
	int i = 0, size = 0;
	char *str;
	char s;

	va_start(ptr, format);
	if (format == NULL)
		exit(98);
=======
	int i = 0, size = 0; 
	int c;

	va_start(ptr, format);

	if (format == NULL)
		return (size);

>>>>>>> a4378064b0659a33263b991a275aa11916a0dfbf
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
<<<<<<< HEAD
				s = va_arg(ptr, int);
				size += write(1, &s, 1);
=======
				c = va_arg(ptr, int);
				size += write(1, &c, 1);
>>>>>>> a4378064b0659a33263b991a275aa11916a0dfbf
				i++;
			}
			else if (format[i + 1] && format[i + 1] == 's')
			{
<<<<<<< HEAD
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
=======
				size += print_str(va_arg(ptr, char *));
>>>>>>> a4378064b0659a33263b991a275aa11916a0dfbf
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
<<<<<<< HEAD

=======
>>>>>>> a4378064b0659a33263b991a275aa11916a0dfbf
	return (size);
}
