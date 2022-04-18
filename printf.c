#include "main.h"
int *select_mode(const char *format, int i, int *arr,char *buffer, int *arrlength );
/**
 * _printf - custom printf function
 * @format : string
 * @... : ellipsis
 *  Return : number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, arr[2];
	int arrlength[2] = {0, 0};
	int *p;
	char buffer[1024];
	va_list args;

	va_start(args, format);
	if ((format == NULL) || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format[i] )
	{
		if (format[i] == '%')
		{
			p = select_mode(format, i + 1, arr, buffer, arrlength);
			if (p[1] == 'd' || p[1] == 'i')
				print_int(args, buffer, arrlength);
			if (p[1] == 's')
				print_string(args, buffer, arrlength);
			if (p[1] == 'c')
				print_char(args, buffer, arrlength);
			if (p[1] == 'b')
				print_binary(args, buffer, arrlength);
			if (p[1] == 'u')
				print_uint(args, buffer, arrlength);
			if (p[1] == 'o')
				print_octal(args, buffer, arrlength);
			if (p[1] == 'x')
				print_hex(args, buffer, arrlength);
			if (p[1] == 'X')
				print_hexCaps(args, buffer, arrlength);
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
int *select_mode(const char *format, int i, int *arr, char *buffer, int *arrlength)
{
	int j = 0;
	char specs[12] = "dixXscuob";
	arr[0] = i;
	arr[1] = 0;

	while (format[i])
	{
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
		if (format[i] == '%')
		{
			buff_push(buffer,'%',arrlength);
			i++;
			break;
		}
		i++;
	}
	return (arr);
}