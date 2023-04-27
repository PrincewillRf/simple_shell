#include "main.h"

/**
 * free_data - frees data struct
 * 
 * @datsh: data struct
 * Return: no return
 */
void free_data(data_shell *datsh)
{
	unsigned int a;

	for (a = 0; datsh->_environ[a]; a++)
	{
		free(datsh->_environ[a]);
	}

	free(datsh->_environ);
	free(datsh->pid);
}
/**
* set_data - initialized data struct
*
*@datashell: data sruct
*@av: argument vect
*return: no return
*/
void set_data(data_shell *datsh, char **av)
{
	unsigned int a;

	datsh->av = av;
	datsh->insert = NULL;
	datsh->args = NULL;
	datsh->status = 0;
	datsh->counter = 1;

	for (a = 0; environ[a]; a++)
	
	datsh->_environ = malloc(sizeof(char *) * (a + 1))
		
	for ( a = 0; environ[a]; a++)
	{
		
		datashell->_environ[a] = _strdup(environ[a]);
	}

	datsh->_environ[a] = NULL;
	datsh->pid = aux_itoa(getpid());
}

/**
*main - Entry point
*
*@ac: argu count
*@av: arg vector
*
*Return: 0 on success
*/
int main(int ac, char **av)
{
	data_shell datsh;
	(void) ac;
	

	signal(SIGINT, get_sigint):
	set_data(&datsh, av);
	shell_loop(&datsh):
	free_data(&datsh);
	if (datsh.status < 0)
		return (255);
	return (datsh.status);
}
