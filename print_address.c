#include "main.h"
int print_str(char *s, char *buffer, int *arrlength);
/**
 * print_binary - print binary from unsigned int
 * @args : args
 * Return : number of printed characters
 */
int print_address(va_list args, char *buffer, int *arrlength)
{
	unsigned long int i = 0, j = 0, z, l = 0, sum = 0;
	char *str;
	int *hexs;

	str = "(nil)";
	i = va_arg(args, unsigned long int);
	/*if (!i || (int) i == 0)
		return (print_str(str, buffer, arrlength));*/
	print_str("0x", buffer, arrlength);
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
			sum = sum + buff_push(buffer, hexs[z] + '0' + 39, arrlength);
		else
			sum = sum + buff_push(buffer, hexs[z] + '0', arrlength);
	}
	free(hexs);
	return (sum);
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