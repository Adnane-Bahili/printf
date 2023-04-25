#include "main.h"
/**
 * _abs_val - absolute value
 * @n: number
 *
 * Return: integer
 */
int _abs_val(int n)
{
	if (n < 0)
	{
		n = n * -1;
		return (n);
	}
	return (n);
}
/**
 * *_inttochrptr - Modifies integer to character pointer
 * @val: value
 * @base: to convert
 *
 * Return: character pointer
 */
char *_inttochrptr(int val, int base)
{
	char buf[1024];
	int n, i;

	if (base < 2 || base > 32)
		exit(1);
	n = _abs_val(val);

	i = 0;

	while (n)
	{
		int r = n % base;

		r = _abs_val(r);
		if (r >= 10)
			buf[i] = 65 + (r - 10);
		else
			buf[i] = 48 + r;
		i++;
		n = n / base;
	}
	if (i == 0)
	{
		buf[i] = '0';
		i++;
	}
	if (val < 0 && base == 10)
	{
		buf[i] = '-';
		i++;
	}
	buf[i] = '\0';
	return (_rev(buf, i));
}
/**
 * *_unstochrptr - Modifies unsigned to character pointer
 * @val: value
 * @base: to convert
 *
 * Return: character pointer
 */
char *_unstochrptr(unsigned int val, unsigned int base)
{
	char buf[1024];
	unsigned int i, r;

	if (base < 2 || base > 32)
		exit(1);

	i = 0;
	while (val)
	{
		r = val % base;
		if (r >= 10)
			buf[i] = 65 + (r - 10);
		else
			buf[i] = 48 + r;
		i++;
		val = val / base;
	}
	if (i == 0)
	{
		buf[i] = '0';
		i++;
	}
	buf[i] = '\0';
	return (_rev(buf, i));
}
/**
 * *_lc_unstochrptr - Modifies unsigned to character pointer with lower case
 * @val: value
 * @base: to convert
 *
 * Return: character pointer
 */
char *_lc_unstochrptr(unsigned int val, unsigned int base)
{
	char buf[1024];
	unsigned int i, r;

	if (base < 2 || base > 32)
		exit(1);

	i = 0;

	while (val)
	{
		r = val % base;

		if (r >= 10)
		{
			buf[i] = 65 + (r - 10);
			if (buf[i] >= 65 && buf[i] <= 90)
				buf[i] += 32;
		}
		else
			buf[i] = 48 + r;
		i++;
		val = val / base;
	}
	if (i == 0)
	{
		buf[i] = '0';
		i++;
	}
	buf[i] = '\0';
	return (_rev(buf, i));
}
