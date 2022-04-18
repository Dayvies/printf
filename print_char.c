#include "main.h"

/**
 * print_char - print one char
 * @args : args
 * Return : 1 if succesfull
 */
int print_char(va_list args)
{
	int i = 0;

	
	i = _putchar(va_arg(args, int));
	
	if (i == 1)
		return 1;
	else
		return 0;
}