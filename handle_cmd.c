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
	pid_t pid;
	int state;
	int i = 0;
	char *cmd;
	struct stat *st = malloc(sizeof(struct stat));
	char *arr[] = {"", NULL};

	cmd = strtok(line_ptr, delim);
	arr[0] = cmd;
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = strtok(NULL, delim);
	}
	if (arr[0] != NULL)
	{
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
						exit(EXIT_FAILURE);
					}
					break;
				default:
					wait(&state);
          if (state != 0)
          {
            errno = 2;
            exit(errno);
          }
      }
		}
		else
			_perror(arr[0]);
	}
	free(st);
}
