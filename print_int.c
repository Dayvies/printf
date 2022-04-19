#include "main.h"
int getlength(unsigned int z, int negative, ul *arr, int *j);
int print_spaces2(ul *arr, int len, int period, char *buffer, int *arrlength);

/**
 * print_int - print an integer
 * @args : args
 * @buffer: buffer
 * @arrlength: buffer length
 * Return : nu,ber of int if succesfull
 */
int print_int(va_list args, char *buffer, int *arrlength, ul *arr)
{
	int i = 0, j = 1, len = 0, negative = 0, period = 0;
	unsigned int z, m;
	int *p;

	p = &j;
	i = va_arg(args, int);
	if (!i)
		i = 0;
	z = i;
	if (i < 0)
	{
		negative = 1;
		z = z * -1;
	}
	m = z;
	len = getlength(z, negative, arr, p);
	print_spaces2(arr, len, period, buffer, arrlength);
	if (negative == 1)
		buff_push(buffer, '-', arrlength);
	if (arr[5] == 1 && negative == 0)
		buff_push(buffer, '+', arrlength);
	if (arr[3] == 1 && negative == 0 && arr[5] == 0)
		buff_push(buffer, ' ', arrlength);
	for (z = 0; j >= 1; z++)
	{
		buff_push(buffer, ((m / j) + 48), arrlength);
		m = m % j;
		j = j / 10;
	}
	period = 1;
	print_spaces2(arr, len, period, buffer, arrlength);
	return (1);
} /**
   * getlength- length
   * @z: number
   * Return: length
   */
int getlength(unsigned int z, int negative, ul *arr, int *j)
{
	int l = 0;
	while (z > 9)
	{
		z = z / 10;
		*j = *j * 10;
		l++;
	}
	l++;
	if (arr[5] == 1 || negative == 1 || arr[3] == 1)
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
int print_spaces2(ul *arr, int len, int period, char *buffer, int *arrlength)
{
	int j, z;
	char c = ' ';

	if (arr[6] == 1 && arr[4] == 0)
		c = '0';
	if (len >= (int) arr[7] || arr[7] == 0)
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