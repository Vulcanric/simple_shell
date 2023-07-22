#include "main.h"

/**
 * _strcmp - Compares the two input strings
 * @s1: The first string
 * @s2: The second sting
 * Return: 0 if they are the same string, or a
 * positive or negative number otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if(s1[i] != s2[i])
			return (s1[i] - s2[i]);

		i++;
	}

	return (0);
}
