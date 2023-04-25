#include "main.h"

/**
 * fun_char - adds character to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_char(char *buf, int comp, va_list val)
{
	int ch = va_arg(val, int);

	if (!ch)
	{
		write(1, "\0\0", 2);
		free(buf);
		exit(0);
	}
	buf[0] = ch;
	return (comp + 1);
}
