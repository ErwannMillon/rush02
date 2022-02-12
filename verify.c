#include <stdlib.h>

int	verify_line(char *str)
{
	int	i;
	int	oldi;
	int	a;

	a = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	oldi = i;
	while (str[i] == ' ' || str[i] == ':')
	{
		i++;
		if (str[i] == ':')
		{
			a++;
			if (a == 2)
				return (0);
		}
	}
	if (i == oldi || a == 0)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (1);
}

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*line_modifier(char *str)
{
	int	i;
	char *new;

	i = 0;
	new = malloc(ft_len(str) * sizeof(char));
	while ('0' <= str[i] && str[i] <= '9')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = ' ';
	new[i + 1] = ':';
	new[i + 2] = ' ';
	i += 3;
	while (str[i] == ' ' || str[i] == ':')
		i++;
	while (str[i] == ' ' || ('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
	{
		if (str[i] == ' ' && str[i - 1] == ' ')
			str[i] = -1;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] != new[i])
		{
			if (str[i] != -1)
				new[i] = str[i];
		}
		i++;
	}
	return (new);
}