#include "main.h"

/**
 * buff_push - push character to end of buff array
 * @buff : buffer
 * @c : char too be stored
 * @arrlength : pointer to length
 * Return: 1 if successfull
 */
int buff_push(char *buff, char c, int *arrlength)
{
	int j, z;

	buff[arrlength[1]] = c;
	if (arrlength[1] == 1023)
	{
		z = buffchar(buff, arrlength[1] + 1);
		arrlength[0] = arrlength[0] + z;
		arrlength[1] = 0;
		for (j = 0; j < 1024; j++)
		{
			buff[j] = '\0';
		}
		return (1);
	}
	arrlength[1] += 1;
	return (1);
}
