
#define NULL ((void *)0)

char *_setnullb(char *str, char *d)
{
	int i = 0, j;

	while (str[i] != '\0')
	{
		j = 0;
		while (d[j])
		{
			if (str[i] == d[j])
			{
				str[i] = '\0';
				break;
			}
			j++;
		}
		i++;
	}

	return (str);
}

char *_strtok(char *str, char *delim)
{
	char *buff = str;
	static char *save_ptr;

	if (str != NULL)
		save_ptr = buff;
	if (str == NULL)
		buff = save_ptr;

	save_ptr = _setnullb(save_ptr, delim);

	while (str == NULL && *save_ptr != '\0')
		save_ptr++;

	if (*save_ptr == buff[0])
		return (save_ptr);

	if (*save_ptr == '\0')
	{
		save_ptr++;
		if (*save_ptr == '\0')
		{
			return (NULL);
		}
//else
		return (save_ptr);
	}

	return (NULL);
}
