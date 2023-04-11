#include "shell.h"

/**
 * _myhistory = displays the history list,one command by line, preceeded with line
 * 	numbers starting at 0.
 * 	@info: structure containing potential arguments.used to maintain function prototype.
 * 	 Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, cc;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	cc = *p;
	*p =0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c
		return (ret);
}
/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on erroe
 */
int set_alias(info_t *info, char *str)
{
	char *pp;

	pp = _strchr(str, '=');
	if (!pp)
		return (1);
	if (!*++pp)
		return (unset_alias(info, str));

	unset_alias(info, str);
	returrn (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *pp = NULL, *a = NULL;

	if (node)
	{
		pp = _str(node->str, '=');
		for (a = node->str; a<= pp; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments, used to maintain
 * 	constyant funciron prototype.
 * Return:n Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info-> *node == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i =1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '=');
	}

