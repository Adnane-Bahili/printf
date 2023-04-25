#include "main.h"

/**
 * fun_rot -  adds converted rot13 string to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int fun_rot(char *buf, int comp, va_list val)
{
	char *str = va_arg(val, char *);
	char *encoded_str = malloc(_strlen(str) + 1);

	_strcpy(encoded_str, str);
	_rot13(encoded_str);

	comp = _asgn(buf, comp, encoded_str);
	free(encoded_str);

	return (comp);
}
