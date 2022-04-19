#include "main.h"
int getlength2(unsigned int z, unsigned int *j);
int print_spaces3(ul *arr, int len, int period, char *buffer, int *arrlength);
/**
 * print_uint - print an undigned integer
 * @args : args
 * Return : nu,ber of int if succesfull
 */
int print_uint(va_list args, char *buffer, int *arrlength, ul *arr)
{
	unsigned int i = 0, j = 1, z, l = 0, period = 0;
	unsigned int *p;

	i = va_arg(args, unsigned int);
	p = &j;

	if (!i)
		i = 0;
	z = i;
	l = getlength2(z, p);
	print_spaces3(arr, l, period, buffer, arrlength);
	for (z = 0;j >= 1; z++)
	{
		buff_push(buffer, (i / j) + '0', arrlength);
		i = i % j;
		j = j / 10;
	}
	print_spaces3(arr, l,1, buffer, arrlength);
	return (1);
}
/**
 * getlength- length
 * @z: number
 * Return: length
 */
int getlength2(unsigned int z, unsigned int *j)
{
	int l = 0;
	while (z > 9)
	{
		z = z / 10;
		*j = *j * 10;
		l++;
	}
	l++;

	return (l);
}
/**
 * print_spaces2 - print spaces or 0s
 * @arr : array
 * @len : length
 * @period : period
 * @buffer : bufffer
 * @arrlength : arrlength
 * Return: int
 */
int print_spaces3(ul *arr, int len, int period, char *buffer, int *arrlength)
{
	int j, z;
	char c = ' ';

	if (arr[6] == 1 && arr[4] == 0)
		c = '0';
	if (len >= (int) arr[7]|| arr[7] == 0)
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