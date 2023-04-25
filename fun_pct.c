#include "main.h"

/**
 * fun_pct - adds '%' to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_pct(char *buf, int comp, va_list val)
{
	(void)val;
	buf[0] = '%';
	return (comp + 1);
}
