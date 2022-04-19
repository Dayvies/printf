#include "main.h"

/**
 * print_binary - print binary from unsigned int
 * @args : args
 * Return : number of printed characters
 */
int print_hexCaps(va_list args, char *buffer, int *arrlength)
{
	unsigned int i = 0, j = 0, z, l = 0, sum = 0;
	int *hexs;

	i = va_arg(args, unsigned int);
	if (!i)
		return buff_push(buffer, '0', arrlength);
	z = i;
	while (z > 0)
	{
		z = z / 10;
		j++;
	}
	hexs = malloc(sizeof(int) * (j));

	for (z = j - 1; i > 0; z--)
	{
		hexs[z] = i % 16;
		i = i / 16;
	}
	for (z = 0; z < j; z++)
	{
		if (hexs[z] == 0 && l == 0)
			continue;
		else
			l = 1;
		if (hexs[z] >= 10)
			sum = sum + buff_push(buffer, hexs[z] + '0' + 7, arrlength);
		else
			sum = sum + buff_push(buffer, hexs[z] + '0', arrlength);
	}
	free(hexs);
	return (sum);
}