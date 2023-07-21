#include "main.h"

/**
 * _perror - writes a custom error message to stderr
 * @cmd: erroneous command
 * Return: void
 */

void _perror(char *cmd)
{
	char *s = "./hsh: 1: ";
	int len = 0;

	while (cmd[len])
		len++;

	write(STDERR_FILENO, s, 10);
	write(STDERR_FILENO, cmd, len);
	write(STDERR_FILENO, ": not found\n", 12);
	exit(127);
}
