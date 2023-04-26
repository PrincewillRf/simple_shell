#include "shell.h"

/**
* is_cmd -checked if a file is an executable commamd
* @infor: the infor struct
* @path: path to the file

* Return: return 1 if true, 0 if false
*/
int is_cmd(infor_t *infor, char *path)
{
	struct stat st;
	(void)infor;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
		return (0);
}

/**
* rep_chars - replicates characters
* @pathstr: Path string
* @begin: begin index
* @end: end index
*
* Return: return pointer to a new buff
*/

char rep_chars(char *pathstr, int begin, int end)
{
	static char buf[1024];

	int a = 0, int e = 0;

	for (e = 0; a = begin ; a  < end; a++)
		if (pathstr[a] != ':')
			buff[e++] = pathstr[a];
	buf[e] = 0;
	return (buf);
}

/**
* find path - look for this cmd in the path string
* @infor: the infor struct
* @pathstr: the path string
* @cmd: the cmd to look for
*
* Return: full path of the cmd if seen or NULL
*/
char *find_path(infor_t *infor, char pathstr, char *cmd)
{
	int a = 0;
	int curr_ind = 0;
	char *path;

	if (!pathstr)
	return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	return (cmd);
}
while (1)
{
	if (!pathstr[a] || pathstr[a] == ':')
	{
		path = rep_chars(pathstr, curr_ind, a)
			if (!*path)
				_strcat(path, "/");
					_strcat(path, cmd);
	}
					if (is_cmd(infor, path)
							return (path);
				if (!pathsr[a])
					break;
					curr_ind = a;
	}
a++;
}
return (NULL);
}
