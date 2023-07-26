#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i])
		i++;

	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}
