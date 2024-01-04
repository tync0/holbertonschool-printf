#include "main.h"

/**
 * write_percent - prints '%' and increases counter if fchar is '%'
 * @fchar: char
 * @size: printed size
 * @count: counter for parent function
 *
 */

void write_percent(char fchar, int *size, int *count)
{
	*size += write(1, "%", 1);
	if (fchar == '%')
		*count = *count + 1;
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
	int x, i = 0, size = 0;
	char s, str[13];

	va_start(ptr, format);
	if (format == NULL)
		exit(98);
	while (format[i])
	{
		if (format[i] != '%')
			size += write(1, format + i, 1);
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
			else if (format[i + 1] && (format[i + 1] == 'd' || format[i + 1] == 'i'))
			{
				x = va_arg(ptr, int);
				size += write(1, num_to_string(x, str), strlen(num_to_string(x, str)));
				i++;
			}
			else if (format[i + 1])
			{
				write_percent(format[i + 1], &size, &i);
			}
		}
		free_array(str);
		i++;
	}
	va_end(ptr);
	return (size == 0 ? -1 : size);
}
