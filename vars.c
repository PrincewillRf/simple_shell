#include "shell.h"

/**
*is_chain -check if current character in the bufferil is chain delimter
*@infor: the argument struct
*@buf: the char buff
*@ptr: addr of the current index buffer
*
*Return: 1 if chain delimeter, else return 0
*/
int is_chain(infor _t *infor, char *buf, size _t *ptr)
{
	size_t b = *ptr;

	if (buf[b] == '|' && buf[b +1] == '|')
	{
		buf[b] = 0;
		b++;
		infor->cmd_buf_type = CMD_OR;
	}
	else if (buf[b] == '&' && buf[b +1] == '&')
	{
		buf[b] = 0;
		b++;
		infor->cmd_buf_type = CMD_AND;
	}
	else if(buf[b] == ';') /* found end of this command */
	{
		buff[b] = 0; /* replace semicolon with null */
		infor->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*ptr = b;
		return (1);
}

/**
* check_chain - tests if we should continue chaining based on the last status
* @infor: argument struct
* @buf: the char buff
* @ptr: addr of the current index in he buff
* @a: starting index in the buff
* @len: length of buff
*
* Return: void
*/
void check_chain(infor_t, infor, char *buff, size_t *ptr, size_t a, size_t len)
{
	size_t b = *ptr;
	if (infor->cmd_buf_type == CMD_AND)
	{
		if (infor->status)
		{
			buf[a] = 0;
			b = len;
		}
	}
if (infor->cmd_buf_type == CMD_OR)
{
	if (infor->status)
	{
		buf[a] = 0;
		b = len;
	}
}
 *ptr=b;
}

/**
* replace_alias - replaces aliases in the tokenizer str
* @infor: argument struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_alias(infor_t *infor)
{
	int a;
	list_t *node;
	char *ptr;

	for(a = 0; a < 5; a++)
	{
		node = node_starts_with(infor->alias, infor->argv[0],'=');
			if (!node)
				return (0);
			free (infor->argv[0];
					ptr = _strchr(node->str='=')
					if (!ptr)
					return (0);
					ptr = _strdp(ptr +1);
					if (!ptr)
					return (0);
					infor->argv[0] = ptr;
	}
					return (1);
}

/**
* replace_vars -  replace vars in the tokenized strings
* @infor: argument struct
*
*Return: 1 if replace, if not replaced 0
*/
int replace_vars(infor_t *infor)
{
int a = 0;
list_t *node;

for (a = 0; infor->[a]; a++)
{
	if (infor->argv[a][0] != '$' || !infor->argv[a][1])
		continue;

	if(!_strcmp(infor->argv[a], "$?"))
	{
		replace_string(&(infor->argv[a]), _strdup(convert_number(infor->status, 10, 0)))
			continue;
	}
if (!_strcmp(infor->argv[a], "$$")
		{
		replace_string(&(infor->argv[a], _strdup(convert_number(getpid(), 10, 0)))
				continue;
				node = node_starts_with(infor->env, &infor->argv[a][1], '=');
if(node)
replace_string(&(infor->argv[a], _strdup(_strchr(node->s,tr'=')+ 1));
	continue;
}
replace_string(&info->argv[a],_strdup(" "));
}
return (0);
}

/**
*replace_string - replaces string
*@old: addr of old string
*@new: new string
*
*Return: 1 return if replaced, 0 if not replaced
*/
int replace_string(char **old, char *new)
{
free(*old);
*old= new;
return (1);
}

