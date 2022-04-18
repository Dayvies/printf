#include "main.h"

/**
 * print_string - print a string char
 * @args : args
 * Return : 1 if succesfull
 */
int print_string(va_list args, char *buffer, int *arrlength)
{
	int i = 0, j = 0, sum = 0;
	char *str;

	str = va_arg(args, char *);
	/*if (!str)
		str = "(null)";*/
	while (str[i])
	{
		j = buff_push(buffer, str[i], arrlength);
		if (j == 1)
			sum = sum + 1;
		i++;
	}
	return (sum);
}