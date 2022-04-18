#include "main.h"

/**
 * print_int - print an integer
 * @args : args
 * @buffer: buffer
 * @arrlength: buffer length
 * Return : nu,ber of int if succesfull
 */
int print_int(va_list args,char *buffer, int *arrlength )
{
	int i = 0, j = 1, z, l = 0, sum = 0;

	i = va_arg(args, int);
	if (!i)
		return buff_push(buffer,'0', arrlength);
	if (i < 0)
	{
		i = i * -1;
		sum = sum + buff_push(buffer , '-', arrlength);
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
		sum = sum + buff_push(buffer, (i / j) + '0', arrlength);
		i = i % j;
		j = j / 10;
	}
	return (sum);
}