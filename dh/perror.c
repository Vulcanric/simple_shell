#include "main.h"

/**
 * _perror - writes a custom error message to stderr
 * @cmd: erroneous command
 * Return: void
 */

void _perror(char *cmd, char *prog)
{
	static int num = 0;
	int len, len2 = 0;

	while (cmd[len])
		len++;

	while (prog[len2])
		len2++;

	num++;
	write(STDERR_FILENO, prog, len2);
	write(STDERR_FILENO, ": ", 2);
	print_num(num);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, len);
	write(STDERR_FILENO, ": not found\n", 12);
//	exit(127);
}

void print_num(int n)
{
	char num;

	if (n > 9)
	{
		print_num(n / 10);
	}

	num = (n % 10) + '0';
	write(1, &num, 1);
}
