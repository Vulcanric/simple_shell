#include "main.h"

/**
 * _perror - writes a custom error message to stderr
 * @cmd: erroneous command
 * Return: void
 */

void _perror(char *cmd)
{
	static int num;
	char *s = "./hsh: ";
	int len = 0;

	num = 0;
	while (cmd[len])
		len++;

	num++;
	write(STDERR_FILENO, s, 7);
	print_num(num);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, len);
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * print_num - prints a number to sterr
 * @n: Number to print out
 * Return: Nothing
 */
void print_num(int n)
{
	char num;

	if (n > 9)
	{
		print_num(n / 10);
	}

	num = (n % 10) + '0';
	write(2, &num, 1);
}
