#include "main.h"

/**
 * main - Executes a shell, recieves commandline arguments, works on them
 * and gives output
 * @argc: Unused parameter
 * @av: Unused parameter
 * @env: Environmental variable
 * Return: Always 0 (On success)
 */
int main(int argc, char *av[], char **env)
{
	size_t n = 0;
	char *line = NULL;

	(void)argc;
	(void)av;
	while (1)
	{
		display_prompt();

		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (_strncmp(line, "exit", 4) == 0)
			_exit_bltin(&line);
		else
			handle_cmd(env, line, " \n\t\v\b\r\f");
	}
	return (0);
}
