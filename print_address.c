#include "main.h"
int print_str(char *s, char *buffer, int *arrlength);
int getlength6(ul *hexs, int j);
void printa(ul  *hexs, char *buffer, int *arrlength, int j);
int print_spaces7(ul *arr, int len, int p, char *buffer, int *length);
/**
 * print_binary - print binary from unsigned int
 * @args : args
 * Return : number of printed characters
 */
int print_address(va_list args, char *buffer, int *arrlength, ul *arr)
{
	unsigned long int i ,len, j = 0, z, ib;
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
	len = getlength6(hexs, j);
	print_spaces7(arr,len,0,buffer, arrlength);
	if (ib == 0)
		print_str(str, buffer, arrlength);
	if ((arr[6] == 0 ||  arr[4] == 1 || arr[7] < len) && (ib > 0))
		print_str(str, buffer, arrlength);
	printa(hexs,buffer, arrlength, j);
	print_spaces7(arr,len,1,buffer, arrlength);
	free(hexs);
	return (1);
}
int print_str(char *s, char *buffer, int *arrlength)
{
	int i = 0;

	while (s[i])
	{
		buff_push(buffer, s[i], arrlength);
		i++;
	}
	return (0);
}
/**
 * getlength- length
 * @z: number
 * Return: length
 */
int getlength6(ul *hexs, int j)
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
	if (j == 0)
		count = 5;
	return (count);
}
void printa(ul *hexs, char *buffer, int *arrlength, int j)
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
int print_spaces7(ul *arr, int len, int p, char *buffer, int *length)
{
	int j, z;
	char c = ' ';

	if (arr[6] == 1 && p == 0)
		c = '0';
	if (len >= (int) arr[7] || arr[7] == 0)
		return (0);
	if (p == 0 && arr[4] == 1)
		return (0);
	if (p == 1 && arr[4] == 0)
		return (0);
	if (arr[6] == 1 && arr[4] == 0)
	{
		buff_push(buffer, '0', length);
		buff_push(buffer, 'x', length);
	}
	j = arr[7] - len;
	for (z = 0; z < j; z++)
		buff_push(buffer, c, length);	
	return (0);
}