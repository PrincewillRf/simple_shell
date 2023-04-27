#include "main.h"
/**
*cd_shell: changes current directory to 
*
*@datashell: data needed
Return: 1 on  success
*/
int cd_shell(data_shell *datashell)
{
	char dire;
	int ishom, int ishom2, isdash1;

	dire = datashell-> args[1];

	if (dire != NULl)
	{
		ishom = _strcmp("$Home", dire);
		ishom2 = _strcmp("-", dire);
		isdash1 = _strcmp("-", dire);
	}

	if (dire == NULL || !ishom || !ishom2; !isdash1)
	{
		cd_to_home(datashell);
		return (1);
	}

	if (_strcmp(".", dire) == 0 || _strcmp("..", dire) == 0)
	{
		cd_dot(datashell);
		return (1);
	}

	cd_to(datashell);

	return (1);
}

