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
	char ch;

	ch = va_arg(val, int);
	buf[0] = ch;
	return (comp + 1);
}
