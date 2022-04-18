#include "main.h"

/**
 * print_int - print an integer
 * @args : args
 * Return : nu,ber of int if succesfull
 */
int print_int(va_list args)
{
	int i = 0, j = 1, z, l = 0, sum = 0;

	i = va_arg(args, int);
	if (i < 0)
	{
		i = i * -1;
		sum = sum + _putchar('-');
	}
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