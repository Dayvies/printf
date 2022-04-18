#include "main.h"
int *select_mode(const char *format, int i, int *arr);
/**
 * _printf - custom printf function
 * @format : string
 * @... : ellipsis
 *  Return : number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, hold, sum = 0, arr[2];
	int *p;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			p = select_mode(format, i + 1, arr);
			if (p[1] == 'd' || p[1] == 'i')
				hold = print_int(args);
			if (p[1] == 's')
				hold = print_string(args);
			if (p[1] == 'c')
				hold = print_char(args);
			if (p[1] == 'b')
				hold = print_binary(args);
			if (p[1] == 'u')
				hold = print_uint(args);
			if (p[1] == 'o')
				hold = print_octal(args);
			if (p[1] == 'x')
				hold = print_hex(args);
			if (p[1] == 'X')
				hold = print_hexCaps(args);
			i = p[0];
			sum = sum + hold;
		}
		else
			sum = sum + _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (sum);
}
int *select_mode(const char *format, int i, int *arr)
{
	int j = 0;
	char specs[] = "sSidbXxuocp";
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
		i++;
	}
	return (arr);
}