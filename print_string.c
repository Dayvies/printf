#include "main.h"

/**
 * print_string - print a string char
 * @args : args
 * Return : 1 if succesfull
 */
int print_string(va_list args)
{
	int i = 0, j = 0, sum = 0;
	char *str;

	str = va_arg(args, char *);
	if (!str)
		str ="(null)";
	while (str[i])
	{
		j = _putchar(str[i]);
		if (j == 1)
			sum = sum + 1;
		i++;
	}
	return (sum);
}