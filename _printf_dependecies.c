#include "main.h"
/**
 * _strlen - string length
 * @s: string variable
 * 
 * Return: Integer
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;
	return (count);
}
/**
 * *_rev - Reverses an array of integers
 * @s: Array
 * @n: elements of array
 * 
 * Return: character pointer
 */
char *_rev(char *s, int n)
{
	int i, au;

	n--;

	for (i = 0; i <= n; i++, n--)
	{
		au = s[i];
		s[i] = s[n];
		s[n] = au;
	}

	return (s);
}
/**
 * *_rot13 - encodes string using rot13
 * @str: string
 * 
 * Return: encoded string
 */
char *_rot13(char *str)
{
	int i, j;
	char chs[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; chs[j]; j++)
		{
			if (str[i] == chs[j])
			{
				str[i] = rot[j];
				break;
			}
		}
	}

	return (str);
}
/**
 * *_strcpy - copies string
 * @dest: pointer 
 * @src: string
 * 
 * Return: array result
 */

void _strcpy(char *dest, char *src)
{
	int l = _strlen(src);
	int i;

	for (i = 0; i <= l; i++)
		dest[i] = src[i];
}
/**
 * _rev_ptr - Reverses pointer
 * @str: string variable
 * 
 * Return: void
 */
void _rev_ptr(char *str)
{
	int i, au;
	int l = _strlen(str) - 1;

	for (i = 0; i <= l; i++, l--)
	{
		au = str[i];
		str[i] = str[l];
		str[l] = au;
	}
}
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
/**
 * fun_add - adds value to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 * 
 * Return: integer
 */
int fun_add(char *buf, int comp, va_list val)
{
	int base = 10;
	char *str = _inttochrptr(va_arg(val, int), base);

	return (_asgn(buf, comp, str));
}
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
/**
 * fun_uns - adds unsigned integer to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 * 
 * Return: integer
 */
int fun_uns(char *buf, int comp, va_list val)
{
	int base = 10;
	unsigned int integer;
	char *str;

	integer = va_arg(val, unsigned int);
	str = _unstochrptr(integer, base);

	return (_asgn(buf, comp, str));
}
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
/**
 * fun_hex - adds unsigned hexadecimal to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 * 
 * Return: integer
 */
int fun_hex(char *buf, int comp, va_list val)
{
	int base = 16;
	unsigned int integer;
	char *str;

	integer = va_arg(val, unsigned int);
	str = _lc_unstochrptr(integer, base);

	return (_asgn(buf, comp, str));
}
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
	int ch = va_arg(val, int);

	if (!ch)
	{
		write(1, "\0\0", 2);
		free(buf);
		exit(0);
	}
	buf[0] = ch;
	return (comp + 1);
}
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
/**
 * fun_bin - adds binary to the buffer
 * @buf: string variable
 * @comp: counter
 * @val: value
 * 
 * Return: integer
 */
int fun_bin(char *buf, int comp, va_list val)
{
	int base = 2;
	unsigned int integer;
	char *str;

	integer = va_arg(val, unsigned int);
	str = _unstochrptr(integer, base);

	return (_asgn(buf, comp, str));
}
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
