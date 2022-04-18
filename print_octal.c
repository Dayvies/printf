#include "main.h"

/**
 * print_binary - print binary from unsigned int
 * @args : args
 * Return : number of printed characters
 */
int print_octal(va_list args, char *buffer, int *arrlength)
{
	unsigned int i = 0, j = 0, z, l = 0, sum = 0;
	int *octal;

	i = va_arg(args, unsigned int);
	if (!i)
		return buff_push(buffer, '0', arrlength);
	z = i;
	while (z > 0)
	{
		z = z / 10;
		j++;
	}
	octal = malloc(sizeof(int) * (j + 2));
	j = j + 2;
	for (z = j - 1; i > 0; z--)
	{
		octal[z] = i % 8;
		i = i / 8;
	}
	for (z = 0; z < j; z++)
	{
		if (octal[z] == 0 && l == 0)
			continue;
		if (octal[z] == 1)
			l = 1;
		sum = sum + buff_push(buffer, octal[z] + '0', arrlength);
	}
	free(octal);
	return (sum);
}