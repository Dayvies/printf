#include "main.h"

/**
 * print_uint - print an undigned integer
 * @args : args
 * Return : nu,ber of int if succesfull
 */
int print_uint(va_list args)
{
	unsigned int i = 0, j = 1, z, l = 0;
	int sum = 0;

	i = va_arg(args, unsigned int);
	z = i;
	while (z > 10)
	{
		z = z / 10;
		j = j * 10;
		l++;
	}
	for (z = 0; z <= l; z++)
	{
		sum = sum + _putchar((i / j) + '0');
		i = i % j;
		j = j / 10;
	}
	return (sum);
}