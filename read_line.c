#include "main.h"

/**
*read_line - read the input strings
*
*@i_eof: return the value getline funct
*Return: input string
*/
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize  = 0;
	*i_eof = getline(&input, &bufsize, stdin);
	return (input);
}
