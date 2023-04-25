#include "main.h"

/**
 * fun_bin - adds binary to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_bin(char *buf, int comp, va_list val)
{
	int base = 2;
	unsigned int integer;
	char *str;

	integer = va_arg(val, unsigned int);
	str = _unstochrptr(integer, base);

	return (_asgn(buf, comp, str));
}
