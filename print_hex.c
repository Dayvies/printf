#include "main.h"
int print_spaces4(ul *arr, int len, int period, char *buffer, int *arrlength);
int getlength3(ul *arr, int *hexs, int j);
void print(int *hexs, char *buffer, int *arrlength, int j);
/**
 * print_binary - print binary from unsigned int
 * @args : args
 * Return : number of printed characters
 */
int print_hex(va_list args, char *buffer, int *arrlength, ul *arr)
{
	unsigned int i = 0, j = 0, z,ib, len;
	int *hexs;

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
	hexs = malloc(sizeof(int) * (j));
	for (z = j - 1; i > 0; z--)
	{
		hexs[z] = i % 16;
		i = i / 16;
	}
	len = getlength3(arr, hexs, j);
	if (ib == 0)
		len = len + 1;
	print_spaces4(arr, len, 0, buffer, arrlength);
	if ((arr[2] == 1 && arr[6] == 0) || (arr[2] == 1 && arr[4] == 1))
	{
		buff_push(buffer, '0', arrlength);
		buff_push(buffer, 'x', arrlength);
	}
	if (ib == 0)
		buff_push(buffer, '0', arrlength);
	print(hexs,buffer, arrlength,j);
	print_spaces4(arr, len, 1, buffer, arrlength);
	free(hexs);
	return (0);
}
/**
 * getlength- length
 * @z: number
 * Return: length
 */
int getlength3(ul *arr, int *hexs, int j)
{
	int i = 0, l = 0, count = 0;
	for (i = 0; i < j; i++)
	{

		if (hexs[i] == 0 && l == 0)
			continue;
		else
			l = 1;
		if (l == 1)
			count++;
	}
	if (arr[2] == 1)
		count = count + 2;
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
int print_spaces4(ul *arr, int len, int period, char *buffer, int *arrlength)
{
	int j, z;
	char c = ' ';

	if (arr[6] == 1 && period == 0)
		c = '0';
	if (len >= (int) arr[7] || arr[7] == 0)
		return (0);
	if (period == 0 && arr[4] == 1)
		return (0);
	if (period == 1 && arr[4] == 0)
		return (0);
	j = arr[7] - len;
	if (arr[2] == 1 && arr[6] == 1 && arr[4] == 0)
	{
		buff_push(buffer, '0', arrlength);
		buff_push(buffer, 'x', arrlength);
	}
	for (z = 0; z < j; z++)
	{
		buff_push(buffer, c, arrlength);
	}
	return (0);
}
void print(int *hexs, char *buffer, int *arrlength, int j)
{	
	int z , l = 0;
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

}
