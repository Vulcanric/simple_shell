#include "main.h"

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
