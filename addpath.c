#include "main.h"

char *path(char *cmd)
{
	char p1[50] = "/bin/";
	char p2[50] = "/usr/bin/";
	struct stat st;

	_strcat(p1, cmd);
	_strcat(p2, cmd);

	if (stat(p1, &st) == 0)
		return (strdup(p1));

	else if (stat(p2, &st) == 0)
		return (strdup(p2));

	return (strdup(cmd));
}
