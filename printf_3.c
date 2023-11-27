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
=======
	int i = 0, size = 0; 
	int c;
>>>>>>> a4378064b0659a33263b991a275aa11916a0dfbf

	va_start(ptr, format);

	if (format == NULL)
<<<<<<< HEAD
		exit(98);
=======
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
				size += print_str(va_arg(ptr, char *));
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
