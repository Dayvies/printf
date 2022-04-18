#include "main.h"

/**
 * print_binary - print binary from unsigned int
 * @args : args
 * Return : number of printed characters
 */
int print_binary(va_list args, char *buffer, int *arrlength )
{
	unsigned int i = 0, j = 0, z, l = 0, sum = 0;
	int *b;

	i = va_arg(args, unsigned int);
	/*if (!i)
		return buff_push(buffer, '0', arrlength);*/
	z = i;
	while (z > 0)
	{
		z = z / 2;
		j++;
	}
	b = malloc(sizeof(int) * j);
	for (z = j - 1; i > 0; z--)
	{
		b[z] = i % 2;
		i = i / 2;
	}
	for (z = 0 ; z < j ; z++)
	{
		if ( b[z] == 0 && l == 0 )
			continue;
		if (b[z] == 1)
			l = 1;
		sum = sum + buff_push(buffer, b[z] + '0', arrlength);
	}
	free(b);
	return (sum);
}