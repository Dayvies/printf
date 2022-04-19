#include "main.h"
int isnum(char c);

/**
 * get_flag - get's flags
 * @arr : arr
 * @f: String
 * i: current position
 *
 */
int get_flag(const char *f, ul *arr, int i)
{
	if (f[i] == '#' && isnum(f[i - 1]) == 0)
	{
		arr[2] = 1;
		arr[1] = 1;
	}
	else if (f[i] == ' ' && isnum(f[i - 1]) == 0)
	{
		if (arr[5] == 0)
			arr[3] = 1;
		arr[1] = 1;
	}
	else if (f[i] == '-' && isnum(f[i - 1]) == 0)
	{
		arr[4] = 1;
		arr[1] = 1;
	}
	else if (f[i] == '+' && isnum(f[i - 1]) == 0)
	{
		arr[5] = 1;
		arr[1] = 1;
		arr[3] = 0;
	}
	else if (f[i] == '0' && isnum(f[i - 1]) == 0)
	{
		arr[6] = 1;
		arr[1] = 1;
	}
	else if ((f[i] == '0' && isnum(f[i - 1]) == 1) || isnum(f[i]) == 1)
	{
		arr[7] = arr[7] * 10 + (f[i] - 48);
		arr[1] = 1;
	}
	else
	{
		arr[1] = 0;
	}
	return (0);
}
/**
 * isnumber - checks if number
 * @c : character
 * Returns : 1 if number 0 if not number
 */
int isnum(char c)
{
	if (c > 48 && c <= 57)
	{
		return (1);
	}
	else
		return (0);
}