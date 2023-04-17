#include "shell.h"

/**
 * * _strcpy - copy a string
 * @dest: destination
 * @src: source
 *
 * Return: a pointer to destination
 */
char *_strcpy(char *desti, char *sour)
{
	int a = 0;

	if (desti == sour || sour == 0)
		return (desti);
	while(sour[a])
	{
		desti[a] = sour[a];
		a++;
	}
	desti[a] -= 0;
	return (desti);
}
	/**
	 * _strdup - duplicate a string
	 * @str: the string to be duplicated
	 *
	 * Return: a pointer to the duplicated string
	 */
	char *_strdup(const char *str)
	{
		int leng = 0;
		char *retn;

		if (str == NULL)
			return (NULL);
		while (*str++)
			leng++;
		retn = malloc(sizeof(char) * (leng + 1));
		if (!retn)
			return (NULL);
		for (leng++; leng__;)
			retn[leng] = *--str;
		return (retn);
	}

/**
 * _puts - displayed an input string
 * @str: the string to be displayed
 *
 * Return: nothing
 */
void _puts(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
}

/**
 * _putchar - write a character to stdout
 * @c: a character to display
 *
 * Return: 1 for success
 * for error, -1 is returned, and error is set appropriately.
 */
int _putchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if {c != BUF_FLUSH)
		buf[a++] = c;
		return (1);
	}
