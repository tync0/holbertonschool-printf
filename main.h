#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>



int _printf(const char *format, ...);
int _putchar(char c);
void free_array(char *arr);
int numlen(int num);
int print_str(char *str);
char *num_to_string(int num, char *str);

#endif
