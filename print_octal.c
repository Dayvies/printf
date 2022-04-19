#include "main.h"
int getlength5(int *arr, int *octal, int j);
int print_spaces6(int *arr, int len, int period, char *buffer, int *arrlength);
void printo(int *octal, char *buffer, int *arrlength, int j);
/**
 * print_binary - print binary from unsigned int
 * @args : args
 * Return : number of printed characters
 */
int print_octal(va_list args, char *buffer, int *arrlength, int *arr)
{
	unsigned int i = 0, j = 0, z,len, ib;
	int *octal;

	i = va_arg(args, unsigned int);
	if (!i)
	{
		i = 0;
		arr[2] = 0;
	}
	z = i;
	ib = i;
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
	len = getlength5(arr, octal, j);
	if (ib == 0)
		len = len + 1;
	print_spaces6(arr, len, 0, buffer, arrlength);
	if (arr[2] == 1)
		buff_push(buffer, '0', arrlength);
	if (ib == 0)
		buff_push(buffer, '0', arrlength);
	printo(octal, buffer, arrlength, j);
	print_spaces6(arr, len, 1, buffer, arrlength);
	free(octal);
	return (1);
}
/**
 * getlength- length
 * @z: number
 * Return: length
 */
int getlength5(int *arr, int *octal, int j)
{
	int i = 0, l = 0, count = 0;
	for (i = 0; i < j; i++)
	{
		if (octal[i] == 0 && l == 0)
			continue;
		else
			l = 1;
		if (l == 1)
			count++;
	}
	if (arr[2] == 1)
		count = count + 1;
	return (count);
}
/**
 * print_spaces4- print spaces or 0s
 * @arr : array
 * @len : length
 * @period : period
 * @buffer : bufffer
 * @arrlength : arrlength
 * Return: int
 */
int print_spaces6(int *arr, int len, int period, char *buffer, int *arrlength)
{
	int j, z;
	char c = ' ';

	if (arr[6] == 1 && period == 0)
		c = '0';
	if (len >= arr[7] || arr[7] == 0)
		return (0);
	if (period == 0 && arr[4] == 1)
		return (0);
	if (period == 1 && arr[4] == 0)
		return (0);
	j = arr[7] - len;

	for (z = 0; z < j; z++)
	{
		buff_push(buffer, c, arrlength);
	}
	return (0);
}
void printo(int *octal, char *buffer, int *arrlength, int j)
{
	int z, l = 0;
	for (z = 0; z < j; z++)
	{
		if (octal[z] == 0 && l == 0)
			continue;
		else
			l = 1;
		buff_push(buffer, octal[z] + '0', arrlength);
	}
}