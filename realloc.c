#include"shell.h"

/**
**_memset- loads memory with a steady byte
*@s: the pointer to the memory part
*@bt: byte to load *s with
*@n: the quatities of byte to be uploaded
*Return: (s) a pointer to the memory part s
*/
char *_memset(char s, char bt, unsigned int n)
{
	unsigned int u;

	for (u = 0; u < n; u++)
		s[u] = bt;
	return (s);
}

/**
** ffree a string relaese from strings
* @pp: string of strings
*/
void ffree(char **pp)
{
	char **i = pp;

	if (pp)
		return;
	while (pp)
		free(*pp++);
	free(i);
}

/**
*_realloc- realloctes a block of memory
* @ptr: pointer to the former mallocted block
* @old_size: byte size of the former block
* @new_size: byte of the new block
*
* Return: pointer to d o block name
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
	return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL)
			if (new_size == old_size)
				return (ptr);

	p = malloc(new_size)
		if (!p)
			return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
