#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * numlen - calculates length of number
 * @num: number
 *
 * Return: length of the number
 */

int numlen(int num)
{
	int i;

	num = num < 0 ? num * -1 : num;
	for (i = 0; num % 10 > 0; i++)
		num = num / 10;

	return (i);
}

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
 * num_to_string - converts number to string
 * @num: num to convert
 * @str: empty array to fill
 *
 * Return: pointer to the string
 */

char *num_to_string(int num, char *str)
{
	int cpNum, len, i, remain;

	len = numlen(num);

	cpNum = num < 0 ? num * -1 : num;
	len = num < 0 ? len + 1 : len;

	for (i = 0; i < len; i++)
	{
		remain = cpNum % 10;
		cpNum = cpNum / 10;
		str[(len - 1) - i] = '0' + remain;
	}
	str[0] = num < 0 ? '-' : str[0];
	return (str);

	return (NULL);
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
	char s, str[13];
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
				size += write(1, num_to_string(x, str), strlen(num_to_string(x, str)));
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
