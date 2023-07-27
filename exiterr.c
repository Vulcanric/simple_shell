#include "main.h"

/**
 * errexit - prints exit error to standard error
 * @code: exit code
 * ./hsh: 1: exit: Illegal number: HBTN
 */

void errexit(char *code)
{
	int len = 0;
	static int num = 1;

	while (code[len])
		len++;

	write(STDERR_FILENO, "./hsh: ", 7);
	print_num(num);
	write(STDERR_FILENO, ": exit: Illegal number: ", 24);
	write(STDERR_FILENO, code, len);
	write(STDERR_FILENO, "\n", 1);
}

