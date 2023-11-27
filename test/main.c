#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int size;
	size =  _printf("%");
	printf("size: %d\n", size);
	size = printf("%");
	printf("size: %d\n", size);
	size = _printf("Should print a single percent sign: %%\n");
	printf("size: %d\n", size);
	size = printf("Should print a single percent sign: %%\n");
	printf("size: %d\n", size);
	size = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("size: %d\n", size);
	size = printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("size: %d\n", size);
	return (0);
}
