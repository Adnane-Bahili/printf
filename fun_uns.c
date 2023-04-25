#include "main.h"

/**
 * fun_uns - adds unsigned integer to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_uns(char *buf, int comp, va_list val)
{
	int base = 10;
	unsigned int integer;
	char *str;

	integer = va_arg(val, unsigned int);
	str = _unstochrptr(integer, base);

	return (_asgn(buf, comp, str));
}
