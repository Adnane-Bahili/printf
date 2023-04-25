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
