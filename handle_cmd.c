#include "main.h"

/**
 * handle_cmd - Executes commands and arguments passed to it
 * @env: The environment variables of the main function
 * @line_ptr: Pointer to string containing commandline input
 * @delim: Delimiting characters that separates
 * commands from their arguments
 * Return: Nothing
 */

void handle_cmd(char **env, char *line_ptr, char *delim)
{
	int i = 0;
	char *cmd;
	struct stat *st = malloc(sizeof(struct stat));
	char *arr[100] = {"", NULL};

	cmd = strtok(line_ptr, delim);
	if (cmd != NULL)
	{
		arr[0] = path(cmd);

		while (arr[i] != NULL)
		{
			i++;
			arr[i] = strtok(NULL, delim);
		}

		checkpath(arr, env, &st);

	}

	free(st);
}
