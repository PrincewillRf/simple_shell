#include "main.h"

/**
 * free_data - frees data struct
 * 
 * @datashell: data struct
 * Return: no return
 */
void free_data(data_shell *datashell)
{
	unsigned int a;

	for (a = 0; datashell->_environ[a]; a++)
	{
		free(datashell->_environ[a]);
	}

	free(datashell->_environ);
	free(datashell->pid);
}
/**
* set_data - initialized data struct
*
*@datashell: data sruct
*@av: argument vect
*return: no return
*/
void set_data(data_shell *datashell, char **av)
{
	unsigned int a;

	datashell->av = av;
	datashell->input = NULL;
	datashell->args = NULL;
	datashell->status = 0;
	datashell->counter = 1;

	for (a = 0; environ[a]; a++)
	
		datashell->_environ = malloc(sizeof(char *) * (a + 1))
		
			for ( a = 0; environ[a]; a++)
			{
			
				datashell->_environ[a] = _strdup(environ[a]);
			}

	datashell->_environ[a] = NULL;
	datashell->pid = aux_itoa(getpid());
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
	data_shell datashell;
	(void) ac;
	

	signal(SIGINT, get_sigint):
	set_data(&datashell);
	shell_loop(&datashell):
	free_data(&datashell);
	if (datashell.status < 0)
		return (255);
	return (datashell.status);
}
