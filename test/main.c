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
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	size = _printf("Salam %s, %c\n", "Cahid", '!');
	printf("size: %d\n", size);
	size = printf("Salam %s, %c\n", "Cahid", '!');	
	printf("size: %d\n", size);

	return (0);
}
