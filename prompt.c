#include "main.h"

/**
 * display_prompt - Displays shell prompt if input is coming
 * from the terminal
 * Return: Nothing
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "$ ", 2);
}
