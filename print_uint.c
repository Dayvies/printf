#include "main.h"

/**
 * print_uint - print an undigned integer
 * @args : args
 * Return : nu,ber of int if succesfull
 */
int print_uint(va_list args, char *buffer, int *arrlength)
{
	unsigned int i = 0, j = 1, z, l = 0;
	int sum = 0;
	*if (!i)
		return buff_push(buffer,'0', arrlength);
	i = va_arg(args, int);
	z = i;
	while (z > 10)
	{
		z = z / 10;
		j = j * 10;
		l++;
	}
	for (z = 0; z <= l; z++)
	{
		sum = sum + buff_push(buffer, (i / j) + '0', arrlength);
		i = i % j;
		j = j / 10;
	}
	return (sum);
}