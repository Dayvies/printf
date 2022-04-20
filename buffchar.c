#include <unistd.h>

/**
 * buffchar - writes the character c to stdout
 * @buffer: hold everything
 * @length: length
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int buffchar(char *buffer, int length)
{
	return (write(1, buffer, length));
}
