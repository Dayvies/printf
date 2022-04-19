#include "main.h"
int print_spaces(int *arr, int len, int period, char *buffer, int *arrlength);
/**
 * print_char - print one char
 * @args : args
 * Return : 1 if succesfull
 */
int print_char(va_list args, char *buffer, int *arrlength, int *arr)
{
	int i = 0, period = 0;

	print_spaces(arr, 1, period, buffer, arrlength);
	i = va_arg(args, int);
	buff_push(buffer, i, arrlength);
	period = 1;
	print_spaces(arr, 1, period, buffer, arrlength);
	return (1);
}
int print_spaces(int *arr, int len, int period, char *buffer, int *arrlength)
{
	int j, z;
	if (len >= arr[7] || arr[7] == 0)
		return (0);
	if (period == 0 && arr[4] == 1)
		return (0);
	if (period == 1 && arr[4] == 0)
		return (0);
	j = arr[7] - len;
	for (z = 0; z < j; z++)
	{
		buff_push(buffer, ' ', arrlength);
	}
	return (0);
}