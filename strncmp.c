#include "main.h"

/**
 * _strncmp - Compares the n number of characters of the two strings
 * @s1: The first string
 * @s2: The second sting
 * @n: Number of chars to compare
 * Return: 0 if they are the same string, otherwise a
 * positive or negative number is returned
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		i++;
	}

	return (0);
}
