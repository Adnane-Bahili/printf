#include "main.h"

/**
 * fun_int - adds integer to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_int(char *buf, int comp, va_list val)
{
	int base = 10;
	char *str = _inttochrptr(va_arg(val, int), base);

	return (_asgn(buf, comp, str));
}
