#include "main.h"
ul *select_mode(const char *format, int i, unsigned long int *arr, char *buffer, int *arrlength);
int redirect(va_list args, ul *p, char *buffer, int *arrlength, ul *arr);
/**
 * _printf - custom printf function
 * @format : string
 * @... : ellipsis
 *  Return : number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, z;
	ul arr[9];
	int arrlength[2] = {0, 0};
	ul *p;
	char buffer[1024];
	va_list args;

	va_start(args, format);
	if ((format == NULL) || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			for (z = 0; z < 8; z++)
				arr[z] = 0;
			p = select_mode(format, i + 1, arr, buffer, arrlength);
			redirect(args, p, buffer, arrlength, arr);
			i = p[0];
		}
		else
			buff_push(buffer, format[i], arrlength);
		i++;
	}
	i = buffchar(buffer, arrlength[1]);

	va_end(args);
	return (arrlength[0] + i);
}
ul *select_mode(const char *format, int i, ul *arr,
		char *buffer, int *arrlength)
{
	int j = 0;
	char specs[14] = "dixXsScuobprR";

	arr[1] = 0;
	arr[0] = i;
	while (format[i])
	{
		j = 0;
		while (specs[j])
		{
			if (specs[j] == format[i])
			{
				arr[1] = format[i];
				break;
			}
			j++;
		}
		if (arr[1] > 50)
		{
			arr[0] = i;
			break;
		}
		get_flag(format, arr, i);
		if (format[i] == '%')
		{
			buff_push(buffer, '%', arrlength);
			break;
		}
		else if (arr[1] == 0)
		{
			buff_push(buffer, '%', arrlength);
			arr[0]--;
			break;
		}

		i++;
	}
	return (arr);
}
int redirect(va_list args, ul *p, char *buffer, int *arrlength, ul *arr)
{
	if (p[1] == 'd' || p[1] == 'i')
		print_int(args, buffer, arrlength, arr);
	if (p[1] == 's')
		print_string(args, buffer, arrlength, arr);
	if (p[1] == 'c')
		print_char(args, buffer, arrlength, arr);
	if (p[1] == 'b')
		print_binary(args, buffer, arrlength);
	if (p[1] == 'u')
		print_uint(args, buffer, arrlength, arr);
	if (p[1] == 'o')
		print_octal(args, buffer, arrlength, arr);
	if (p[1] == 'x')
		print_hex(args, buffer, arrlength, arr);
	if (p[1] == 'X')
		print_hexCaps(args, buffer, arrlength, arr);
	if (p[1] == 'S')
		print_String(args, buffer, arrlength);
	if (p[1] == 'p')
		print_address(args, buffer, arrlength, arr);
	if (p[1] == 'r')
		print_rev(args, buffer, arrlength);
	if (p[1] == 'R')
		print_rot13(args, buffer, arrlength);
	return (1);
}