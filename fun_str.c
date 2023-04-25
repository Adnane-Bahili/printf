#include "main.h"

/**
 * fun_str - adds string to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_str(char *buf, int comp, va_list val)
{
	char *str = va_arg(val, char *);

	if (!str)
		str = "(null)";
	return (_asgn(buf, comp, str));
}
