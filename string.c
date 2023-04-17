#include "shell.h"

/**
 * _strlen - returns the length oif a string
 * @s: the strings length to check
 * *
 * Return: number length of a string
 */
int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}

/**
 * _strcmp - performs lexicographic comparisions of two strings
 * @str1: first string
 * @str2:second string
 *
 * Return: negative if str1< str2,positive if str1> str2, zero if str1 == str2
 */
int _strcmp (*str1 && *str2)
{
	if (*str1 && *str2)
	{
		if (*str1 != *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * start_with - look if needle starts with haystack
 * @haystack: string to search for
 * @needle: substring tom be find
 * 
 * Return: address of next char oif haystack or NULL
 */
char *starts_with(const char *haystk, const char *nedle)
{
	while (*nedle)
		if (*nedle++ != *haystk++)
			return (NULL);
	return ((char *)haystk);
}

/**
 * _strcat - concatenate two strings
 * @dest: destination of buffer
 * @src: source of buffer
 *
 * Return: a pointer to destination of buffer
 */
char *_strcat(char *desti, char *sour)
{
	char *retn = desti;

	while (*desti)
		desti++;
	while (*sour)
		*desti++ = *sour++;
		*desti = *sour;
	return (retn);
}	
