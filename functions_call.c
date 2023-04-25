#include "main.h"
/**
 * _asgn - assigns and counts function
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int _asgn(char *buf, int comp, char *val)
{
	int i = 0;

	while (val[i])
	{
		buf[i] = val[i];
		comp++;
		i++;
	}
	return (comp);
}
/**
 * _rev_asgn - reverses assigned function and counts it
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: integer
 */
int _rev_asgn(char *buf, int comp, char *val)
{
	int l = _strlen(val);
	int i;

	for (i = 0; i <= l; i++)
	{
		buf[i] = val[l - i];
		comp++;
	}
	return (comp);
}
