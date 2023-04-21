#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: structure containing potential arguments, used to maintain
 * 	constant prototype.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments, used to mainatin
 * --------------------constant function prototype
 *  Return: 1 on delete, 0 otherwise
 *  @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_charged);
}

/**
 * _setenv - initialize a new environment variable,
 * -----------------or modify an existing one
 *  @info:structure containing arguments
 *  @var: the string env var var property
 *  @value: the string new var value
 *  Return; always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buuff + NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buuff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buuff)
		return (1);
	_strcpy(buuff, var);
	_strcat(buuff, "=");
	_strcat(buuff, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buuff;
			info->env_changed = 1;
			return (0);
		}
		node = node ->next;
	}
	add_node_end(&(info->env), buuff, 0);
	free(buuff);
	info->env_changed = 1;
	return (0);
}
