#include "main.h"
int print_str(char *s, char *buffer, int *arrlength);
/**
 * print_binary - print binary from unsigned int
 * @args : args
 * Return : number of printed characters
 */
int print_address(va_list args, char *buffer, int *arrlength)
{
	unsigned long int i , j = 0, z, l = 0;
	char *str;
	unsigned int *hexs;

	str = "(nil)";
	i = va_arg(args, unsigned long int);
	if (!i || i == 0)
		return (print_str(str, buffer, arrlength));
	str = "0x";
	print_str(str, buffer, arrlength);
	z = i;
	while (z > 0)
	{
		z = z / 10;
		j++;
	}
	hexs = malloc(sizeof(unsigned int) * (j));
	for (z = 0; z < j; z++)
		hexs[z] = 0;

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
			buff_push(buffer, hexs[z] + '0' + 39, arrlength);
		else
			buff_push(buffer, hexs[z] + '0', arrlength);
	}
	free(hexs);
	return (1);
}
int print_str(char *s, char *buffer, int *arrlength)
{
	int i = 0;

	while (s[i])
	{
		buff_push(buffer, s[i], arrlength);
		i++;
	}
	return (0);
}