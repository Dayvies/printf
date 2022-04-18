#include "main.h"

/**
 * print_int - print an integer
 * @args : args
 * @buffer: buffer
 * @arrlength: buffer length
 * Return : nu,ber of int if succesfull
 */
int print_int(va_list args, char *buffer, int *arrlength)
{
	int i = 0, j = 1, sum = 0;
	unsigned int z, m, l = 0;
	i = va_arg(args, int);
	/*if (!i)
		return buff_push(buffer, '0', arrlength);*/
	z = i;
	if (i < 0)
	{
		sum = sum + buff_push(buffer, '-', arrlength);
		z = z * -1;
	}
	m = z;
	while (z > 9)
	{
		z = z / 10;
		j = j * 10;
		l++;
	}
	for (z = 0; z <= l; z++)
	{
		sum = sum + buff_push(buffer, ((m / j) + 48), arrlength);
		m = m % j;
		j = j / 10;
	}
	return (sum);
}