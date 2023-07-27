#include "main.h"

/**
 * _exit_bltin - Exit shell with a status N, if N is omitted,
 * it exits with zero
 * @input: Pointer to the command line input
 * Return: Nothing
 */
void _exit_bltin(char **input)
{
	int status = 0;
	char line[2048];
	char *tmp, *cmd, *to_free;

	_strcpy(line, *input);
	cmd = strtok(line, " \n\t\v");
	tmp = cmd;

	if (_strcmp(cmd, "exit") == 0)
	{
		to_free = *input;
		tmp = strtok(NULL, " \n\t\v\b");

		if (tmp == NULL)
		{
			free(to_free);
			exit(0);
		}
		else
		{
			status = _atoi(tmp);

			if ((status == 0 && _strcmp(tmp, "0") != 0) || status < 0)
			{
				free(to_free);
				errexit(tmp);
				exit(2);
			}
			free(to_free);
			exit(status);
		}
	}
}

/**
 * _atoi - Converts string to an integer number
 * @str: Pointer to the string to convert
 * Return: the integer gotten from string on success, else 0
 */
int _atoi(char *str)
{
	int i = 0, num = 0, sign = 1;

	while ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}

	num = num * sign; /* Getting the number signed */

	return (num);
}
