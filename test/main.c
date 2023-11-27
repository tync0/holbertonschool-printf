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
	return (0);
}
