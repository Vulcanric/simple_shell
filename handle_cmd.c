#include "main.h"

/**
 * handle_cmd - Executes commands and arguments passed to it
 * @env: The environment variables of the main function
 * @line_ptr: Pointer to string containing commandline input
 * @delim: Delimiting characters that separates
 * commands from their arguments
 * Return: Nothing
 */
void handle_cmd(char **env, char **line_ptr, char *delim)
{
	pid_t pid, pid2;
	int state, state2, i = 0;
	char *cmd, *arr[100] = {"", NULL}, line_cp[2048];
	struct stat *st = malloc(sizeof(struct stat));

	strcpy(line_cp, *line_ptr);
	cmd = strtok(line_cp, delim);
	if (cmd != NULL)
	{
		arr[0] = cmd;
		while (arr[i] != NULL)
		{
			i++;
			arr[i] = strtok(NULL, delim);
		}

		if (stat(arr[0], st) == 0)
		{
			pid = fork();
			switch (pid)
			{
				case -1:
					free(st);
					exit(EXIT_FAILURE);
				case 0:
					if (execve(arr[0], arr, env) == -1)
					{
						free(st);
						exit(EXIT_SUCCESS);
					}
					break;
				default:
					wait(&state);
					free(st);
					pid2 = fork();
					if (pid2 == 0)
						exit(0);
					else
						wait(&state2);
			}
		}
		else
		{
			_perror(arr[0]);
			free(st);
			if (isatty(STDIN_FILENO) == 0)
				exit(127);
		}
	}
	else
	{
		free(*line_ptr);
		free(st);
	}
}
