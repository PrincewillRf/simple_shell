#include "shell.h"

/**
 * _strcpy - copy a string
 * @dest:destination
 * @src:source
 *
 * Return:a pointer tdestination
 */
char *_strcpy(char *desti, char *sour)
{
	int a = 0;

	if (desti == sour || sour == 0)
		return (desti);
	while (sour[a])
	{
		desti[a] = sour[a];
		a++;
	}
	desti[a] = 0;
	return (desti);
}
/**
 * _strdup - duplicate a string
 * @str:the string to be duplicated
 *
 * Return:pointer to the duplicated string
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
	for (leng++ ; leng__)
		retn[leng] = *--str;
	return (retn);
}

/**
 * _puts - displayed an input string
 * @str: the string to be displayed
