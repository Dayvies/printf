#include "main.h"
int print_space(int *arr, int len, int period, char *buffer, int *arrlength);
/**
 * print_string - print a string char
 * @args : args
 * Return : 1 if succesfull
 */
int print_string(va_list args, char *buffer, int *arrlength, int *arr)
{
	int i = 0, j = 0;
	char *str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[j] != '\0')
		j++;
	
	print_space(arr,j,0, buffer, arrlength);
	while (str[i] != '\0')
	{
		buff_push(buffer, str[i], arrlength);
		i++;
	}
	print_space(arr,j,1, buffer, arrlength);
	return (0);
}
int print_space(int *arr, int len, int period, char *buffer, int *arrlength)
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