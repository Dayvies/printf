#include "main.h"

/**
 * print_rot13 - plus 13
 * @args: arguments
 * @buffer: buffer
 * @arrlength: buffer length
 * Return: string
 * On error, 0 is returned, and errno is set appropriately.
 */
void print_rot13(va_list args, char *buffer, int *arrlength)
{
	char a[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[53] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i = 0, z = 0;
	char *s1 = va_arg(args, char *);

	while (s1[i])
	{
		if (s1[i] < 'A' || (s1[i] > 'Z' && s1[i] < 'a') || s1[i] > 'z')
			buff_push(buffer, s1[i], arrlength);
		else
		{
			for (z = 0; z <= 52; z++)
			{
				if (s1[i] == a[z])
				{
					buff_push(buffer, b[z], arrlength);
					break;
				}
			}
		}
		i++;
	}
}
