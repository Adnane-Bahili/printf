#ifndef MAIN_H
#define MAIN_H


#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct ptr
{
	char *c;
	int (*f)(char *, int, va_list);
} ptr_ch;

int (*prmts_ch(char specifier))(char *, int, va_list);
int _printf(const char *format, ...);

int _putchar(char c);
int _prtstr(char *str);
char *conv(unsigned long int num, int b, int uc);
int fun_STR(char *buf, int comp, va_list val);




int _strlen(char *s);
char *_rev(char *s, int n);
char *_rot13(char *str);
void _strcpy(char *dest, char *src);
void _rev_ptr(char *str);
int _abs_val(int n);
char *_inttochrptr(int val, int base);
char *_unstochrptr(unsigned int val, unsigned int base);
char *_lc_unstochrptr(unsigned int val, unsigned int base);
int _asgn(char *buff, int count, char *val);
int _rev_asgn(char *buff, int count, char *val);
int fun_add(char *buf, int comp, va_list val);
int fun_bin(char *buf, int comp, va_list val);
int fun_char(char *buf, int comp, va_list val);
int fun_hex(char *buf, int comp, va_list val);
int fun_HEX(char *buf, int comp, va_list val);
int fun_int(char *buf, int comp, va_list val);
int fun_oct(char *buf, int comp, va_list val);
int fun_str(char *buf, int comp, va_list val);
int fun_rev(char *buf, int comp, va_list val);
int fun_rot(char *buf, int comp, va_list val);
int fun_pct(char *buf, int comp, va_list val);
int fun_uns(char *buf, int comp, va_list val);


#endif /* MAIN_H */
