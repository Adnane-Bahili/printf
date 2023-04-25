#include "main.h"
#include <stddef.h>

/**
 * *prmts_ch - parameter checker
 * @specifier: string variable
 *
 * Return: specifier
 */
int (*prmts_ch(char specifier))(char *, int, va_list)
{
	int j = 0;

	ptr_ch arg_ptr[] = {
		{"b", fun_bin},
		{"c", fun_char},
		{"d", fun_add},
		{"i", fun_int},
		{"o", fun_oct},
		{"r", fun_rev},
		{"R", fun_rot},
		{"s", fun_str},
		{"u", fun_uns},
		{"x", fun_hex},
		{"X", fun_HEX},
		{"%", fun_pct},
		{NULL, NULL}
	};
	while (arg_ptr[j].c)
	{
		if (specifier == *arg_ptr[j].c)
		{
			return (arg_ptr[j].f);
		}
		j++;
	}
	return (NULL);
}
/**
 * _printf - prints input
 * @format: string
 * Return: printed input
 */
int _printf(const char *format, ...)
{
	int  i, comp;
	char *buf;
	va_list arg_val;
	int (*fun)(char *, int, va_list);

	i = comp = 0;
	buf = malloc(4000);
		if ((!format || !buf) || (format[0] == '%' && format[1] == '\0'))
			return (-1);
	va_start(arg_val, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			buf[comp] = format[i];
			comp++;
		}
		else
		{
			if (format[i + 1] == '\0')
				return (-1);
			fun = prmts_ch(format[i + 1]);
			if (!fun)
			{
				buf[comp] = '%';
				comp++;
			}
			else
			{
				comp = fun(&buf[comp], comp, arg_val);
				i++;
			}
		}
		i++;
	}
	write(1, buf, comp);
	va_end(arg_val);
	free(buf);
	return (comp);
}
