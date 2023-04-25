#include "main.h"

/**
 * fun_HEX - adds unsigned hexadecimal to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_HEX(char *buf, int comp, va_list val)
{
	int base = 16;
	unsigned int integer;
	char *str;

	integer = va_arg(val, unsigned int);
	str = _unstochrptr(integer, base);

	return (_asgn(buf, comp, str));
}
