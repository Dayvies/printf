#include "main.h"
int print_str(char *s, char *buffer, int *arrlength, ul r, ul *arr);
int getlength6(ul *hexs, int j, ul *arr);
void printa(ul *hexs, char *buffer, int *arrlength, int j);
int print_spaces7(ul *arr, int len, int p, char *buffer, int *length);
/**
 * print_address - print binary from unsigned int
 * @args : args
 * @buffer : buff
 * @arrlength : length array
 * @arr : array
 * Return: number of printed characters
 */
int print_address(va_list args, char *buffer, int *arrlength, ul *arr)
{
	unsigned long int i, len, j = 0, z, ib;
	char *str;
	unsigned long int *hexs;

	str = "0x";
	i = va_arg(args, unsigned long int);
	if (!i || i == 0)
	{
		str = "(nil)";
		arr[6] = 0;
	}
	z = i;
	ib = i;
	while (z > 0)
	{
		z = z / 10;
		j++;
	}
	hexs = malloc(sizeof(unsigned long int) * (j));
	for (z = 0; z < j; z++)
		hexs[z] = 0;
	for (z = j - 1; i > 0; z--)
	{
		hexs[z] = i % 16;
		i = i / 16;
	}
	len = getlength6(hexs, j, arr);
	print_spaces7(arr, len, 0, buffer, arrlength);
	if (ib == 0)
		print_str(str, buffer, arrlength, 0, arr);

	if ((arr[6] == 0 || arr[4] == 1 || arr[7] < len) && (ib > 0))
		print_str(str, buffer, arrlength, 1, arr);
	printa(hexs, buffer, arrlength, j);
	print_spaces7(arr, len, 1, buffer, arrlength);
	free(hexs);
	return (1);
}
/**
 * print_str - print string
 * @s: string
 * @buffer : hold everything
 * @arrlength : length
 * @r : r
 * @arr : array
 * Return: integer
 */
int print_str(char *s, char *buffer, int *arrlength, ul r, ul *arr)
{
	int i = 0;

	if (r == 1)
	{
		if (arr[5] == 1)
			buff_push(buffer, '+', arrlength);
		if (arr[3] == 1 && arr[5] == 0)
			buff_push(buffer, ' ', arrlength);
	}

	while (s[i])
	{
		buff_push(buffer, s[i], arrlength);
		i++;
	}
	return (0);
}
/**
 * getlength6- length
 * @hexs: malloc array
 * @arr : array
 * @j : j
 * Return: length
 */
int getlength6(ul *hexs, int j, ul *arr)
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
	count = count + 2;
	if (arr[5] == 1 || arr[3] == 1)
		count++;
	if (j == 0)
		count = 5;
	return (count);
}
/**
 * printa- print address
 * @hexs: malloc array
 * @buffer : buff
 * @arrlength :arrlength
 * @j : j
 * Return: void
 */
void printa(ul *hexs, char *buffer, int *arrlength, int j)
{
	int z, l = 0;

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
/**
 * print_spaces7- print address
 * @length: malloc array
 * @arr : array
 * @len : j
 * @buffer: buffer
 * @p: period
 * Return: void
 */
int print_spaces7(ul *arr, int len, int p, char *buffer, int *length)
{
	int j, z;
	char c = ' ';

	if (arr[6] == 1 && p == 0)
		c = '0';
	if (len >= (int)arr[7] || arr[7] == 0)
		return (0);
	if (p == 0 && arr[4] == 1)
		return (0);
	if (p == 1 && arr[4] == 0)
		return (0);
	if (arr[6] == 1 && arr[4] == 0)
	{
		if (arr[5] == 1)
			buff_push(buffer, '+', length);
		if (arr[3] == 1 && arr[5] == 0)
			buff_push(buffer, ' ', length);

		buff_push(buffer, '0', length);
		buff_push(buffer, 'x', length);
	}
	j = arr[7] - len;
	for (z = 0; z < j; z++)
		buff_push(buffer, c, length);
	return (0);
}
