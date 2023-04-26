#include "shell.h"
/**
*hsh -main shell loop
*@infor: the argument & return infor struct
*@av: the argument vector from main()
*
*Return: return 0 if succeed, return 1 if error, or there is error code
*/
int hsh(infor_t *infor, char **av)
{
	ssize_t r = 0;
	int builtin_retrn = 0;

	while ( r != -1 && builtin_retrn != -2)
		(
		 clear_infor(infor);
		 if (interative(infor))
		 _puts("$ "):
		 _eputchar(BUF_FLUSH);
		 r = get_input(infor);
		 if (r != -1)
		 {
		 set_infor(infor, av):
		 if (builtin_retrn = find_builtin(infor);
		if (builtin _retrn == -1)
			find_cmd(infor);
		}
		else if (interative(infor))
		_putchar('\n');
		free_infor(infor, 0);
		}
		write_history(infor);
		free_info(infor, 1);
		if (!interactive(infor) && infor-> status)
		exit(infor->status);
		if (builtin_retrn == -2)
		{
			if (infor ->err_numb == -1)
			exit(infor->status);
			exit(infor->err_numb);
		}
		return (builtin_retrn);
}
/**
* find_builtin - look for builtin commmand
* @infor: the argument & return infor struct
*
* Return: - return 1 if builtin not command found,
* return 0 if builtin command executed successful
* return 1 if builtin commmand found but not successful,
* -2 if builtin signals exit()
*/
int find_builtin(infor_tt *infor)
{
	int a, built_in_retrn = -1;
	builtin_table builtin b|[] = 
	{
	{"exit", _myexit},
	{"env", _myenv},
	{"help", _myhelp},
	{"history", _myhistory},
	{"setenv", _mysetenv},
	{"unsetenv", _myunsetenv},
	{"cd", _mycd},
	{"alias", _myalias},
	{NULL, NULL},
	};
	
	for(a = 0; builtint b|[a].type; a++)

		if (_strcmp(info->argv[0], builtint |[a].type) == 0)
		{
			infor->line_count++;
			built_int_retrn = builtintb|[a].func(infor)
			break;
		}
	return (built_in_retrn);
}
/**
* find_cmd - look for a commmand in the path
* @infor: the argument & return infor struct
* Return: void
*/
void find_cmd(infor_t *infor)
{
	char *pathe = NULL;
	int a, c;

	infor->pathe = infor-> arg[0];
	if (infor->linecount_flag == 1)
	{
		infor->line_count++;
		infor->linecount_flag = 0;
	
	}
	for ( a = 0; c = 0; inforr->arg[a]; a++)
		if (!is_delim(infor->arg[a], "\t\n"))
			c++;
	if(!c)
		return;
	pathe = find_path(infor, _getenv(infor, "PATH="), infor-> argv[0]);
	if(pathe)
	{
		infor->pathe = pathe;
		fork_cmd(infor);
	}
	else
	{
		if ((interative(infor) || _getenv(infor, "PATH=") || infor-> argvarg[0][0] == '/'0 && is _cmd(infor, infor->arg[0]))
				fork_cmd(infor);
				else if (*(infor->arg) !='\n')
				{
				infor->status = 127;
				print_error(infor, "not found\n");
	}
				}
}
	
/**
* fork_cmd - forks a an execute thread to run cmd
* @infor: the argument & return infor struct
* 
* Return: void
*/
void fork_cmd(infor_t *infor)
{
pid_t child_pid;

child_pid = fork ();
if (child_pid == -1)
{
	/*TODO: i PUT ERROR FUNCTION */
	perror("Error:");
	return;
}
if (child_pid == 0)
{
	if (execve(infor->path, infor->argv, get_environ(infor)) == -1)
	{
		free_infor(infor, 1);
		if (errno == EACCES)
			exit(126);
		exit(1);
	}
	/*TODO: THERE EROR FUNCTION*/
}
else
{
	wait(&(infor->status));
	if (WIFEEXITED(infor->status))
	{
		infor->status = WEXITSTATUS(infor->status);
		if (infor->status == 126)
			print_error(infor, "permission not allowed\n");
	}
}
}



