#include "main.h"
/**
 * print_rev - check length of string
 * @str : string
 * Return: 0
 * On error, 0 is returned, and errno is set appropriately.
 */
void print_rev(va_list args, char *buffer, int *arrlength)
{
	int c = 0, i = 0;
	char *str;

	str = va_arg(args, char *);
	while (str[c])
		c++;
	for (i = (c - 1); i >= 0; i--)
		buff_push(buffer, str[i], arrlength);
}
