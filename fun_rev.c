#include "main.h"

/**
 * fun_rev - adds reversed string to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_rev(char *buf, int comp, va_list val)
{
	char *str = va_arg(val, char *);
	char *rev_str = malloc(_strlen(str) + 1);

	_strcpy(rev_str, str);
	_rev_ptr(rev_str);

	comp = _asgn(buf, comp, rev_str);
	free(rev_str);

	return (comp);
}
