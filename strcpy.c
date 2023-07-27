#include "main.h"

/**
 * _strcpy - Copy the content of one string to another
 * @dest: Destination string to recieve content
 * @src: Source string to get the content from
 * Return: Destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
