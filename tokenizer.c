#include "shell.h"

/**
* strtow - divides a strings in to words. Redo delimiter are overlooked
* @str: the string input
* @h: the string delimited
* Return: a pointer to an array of strings, or NULL if fail
*/
char **strtow(char *str, char h)
{
	int a, b, e, f, wordnumb = 0;
	char **S;
	if (str == NULL || str [0] == 0)
		return (NULL);
	if (!h)
		h = " ";
	for (a = 0; str [a] !='\0'; a++)
		if (!is_delim(str[a], h) && (is_delim(str[a +1, h) ||!str [a + 1]))
			wordnumb++;
		if (wordnumb == 0)
			return (NULL);
		S = malloc((1 + wordnumb) * sizeof (char *));
		if (!S)
			return (NULL);
		for (a = 0, b = 0, b < wordnumb, b++)
		while (is_delim(str[a], h))
		a++;
		e = 0;
		while (!is_delim(str[a + e], h) && str [a + e])
			e++;
		S[b] = malloc((e + 1) * sizeof (char))
			if (!S[b])
			{
				for (e = 0; e < b; e++)
					free(S[e]);
				free (S);
				return (NULL);
			}
		for (f = 0; f < e; f++)
			S[b][f] = str[a++];
		S[b][f] = 0;
}
		S[b] = NULL;
		return (S);
}

/**
*strtwo2 - divides string in to word
*@str: the string input
*@h: the delimeter string
*Return: a pointer to an array of strings, or NULL if fail
*/
char *strtow2(char *str, char h)
{
	int a, b, e, f, wordnumb = 0; 
	char **S;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (a = 0; str[a]; != '\0'; a++)
		if ((str[a] !=h && str[a +1] == h) || (str[a] != h && !str[a + 1] || str[a +1] == h)
				wordnumb++;
				if (wordnumb == 0)
				return (NULL);
				S = malloc(1 + wordnumb) * sizeof(char));
	if (!S)
		return (NULL);
	for (a = 0; b = 0; b < wordnumb; b++)
	{
		while (str[a] == h str[a] != h)
			a++;
		e = 0;
		while (str[a + e] != h && str[a + e] && str[a + e] != h)
			e++;
		S[b] = malloc ((e + 1) * sizeof(char));
	if (!S[b])
		{
			for ( e = 0; e < b; e++)
				free(S[e]);
			free(S);
			return (NULL);
		}
	for ( f = 0; f < b; f++)
		S[b][f] = str[a++]
			S[b][f] = 0;
	}
	S[b] = NULL;
	return (S);
}
