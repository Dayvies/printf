#include "main.h"
int nonprint(char c, char *buffer, int *arrlength);
/**
 * print_string - print a string char
 * @args : args
 * Return : 1 if succesfull
 */
int print_String(va_list args, char *buffer, int *arrlength)
{
	int i = 0;
	char *str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		if((str[i] < 32 && str[i] > 0) || str[i] >= 127)
			nonprint(str[i], buffer , arrlength);
		else
			buff_push(buffer, str[i], arrlength);		
		i++;
	}
	return (1);
}
int nonprint(char c, char *buffer, int *arrlength)
{
	int z, i;
	int *hexs;

	i = c;
	buff_push(buffer,'\\', arrlength);
	buff_push(buffer,'x', arrlength);
	hexs = malloc(sizeof(int) * (2));
	hexs[1] = 0;

	for (z = 2 - 1; i > 0; z--)
	{
		hexs[z] = i % 16;
		i = i / 16;
	}
	for (z = 0; z < 2; z++)
	{
		
		if (hexs[z] >= 10)
			buff_push(buffer, hexs[z] + '0' + 7, arrlength);
		else
			buff_push(buffer, hexs[z] + '0', arrlength);
	}
	return (0);
}
