#include "main.h"
/**
 * checkpath - checks if an exec path is valid and executes it
 * @arr: array of parameter to be executed
 * @env: environment variables
 * @st: pointer to stat for storing path information
 * @line_ptr: memory location of strings read from line
 * Return: void
 */

void checkpath(char **arr, char **env, struct stat **st, char *line_ptr)
{
	pid_t pid;
	int state;

	if (stat(arr[0], *st) == 0)
	{
		pid = fork();
		switch (pid)
		{
			case -1:
				free(*st);
				exit(EXIT_FAILURE);
			case 0:
				if (execve(arr[0], arr, env) == -1)
				{
					free(*st);
					exit(EXIT_FAILURE);
				}
				break;
			default:
				wait(&state);
				free(arr[0]);
				if (state != 0)
				{
					errno = 2;
					free(*st);
					free(line_ptr);
					exit(errno);
				}
		}
	}
	else
	{
		_perror(arr[0]);
		if (isatty(STDIN_FILENO) == 0)
		{
			exit(127);
		}
	}
}
