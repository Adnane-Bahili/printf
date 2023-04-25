#include "main.h"

/**
 * fun_oct - adds octal to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_oct(char *buf, int comp, va_list val)
{
	int base = 8;
	unsigned int integer;
	char *str;

	integer = va_arg(val, unsigned int);
	str = _unstochrptr(integer, base);

	return (_asgn(buf, comp, str));
}
