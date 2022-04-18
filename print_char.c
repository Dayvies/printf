#include "main.h"

/**
 * print_char - print one char
 * @args : args
 * Return : 1 if succesfull
 */
int print_char(va_list args, char *buffer, int *arrlength)
{
	int i = 0;

	
	i = buff_push(buffer , va_arg(args,int), arrlength);
	
	if (i == 1)
		return 1;
	else
		return 0;
}