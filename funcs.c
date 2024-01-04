#include "main.h"

/**
 * free_array - frees array
 * @arr: array or string to free
 *
 * Return: nothing
 */

void free_array(char *arr)
{
	int i, length;

	length = strlen(arr);

	for (i = 0; i < length; i++)
		arr[i] = '\0';
}

/**
 * numlen - calculates length of number
 * @num: number
 *
 * Return: length of the number
 */

int numlen(int num)
{
	int i;

	if (num == 0)
		return (1);

	if (num == INT_MIN)
		num = num - 1;
	else
		num = num < 0 ? num * -1 : num;

	for (i = 0; num > 0; i++)
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
	if (num == INT_MIN)
		cpNum = num - 1;
	else
		cpNum = num < 0 ? num * -1 : num;
	len = num < 0 ? len + 1 : len;

	for (i = 0; i < len; i++)
	{
		remain = cpNum % 10;
		cpNum = cpNum / 10;
		str[(len - 1) - i] = '0' + remain;
	}

	if (num == INT_MIN)
		str[len - 1] += 1;

	str[0] = num < 0 ? '-' : str[0];
	return (str);

	return (NULL);
}


