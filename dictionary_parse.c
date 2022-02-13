#include "ft_includes.h"

int	verify_line(char *str)
{
	int	i;
	int	comparison;
	int	a;

	a = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	comparison = i;
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	comparison = i;
	while (32 <= str[i] && str[i] <= 126)
	{
		i++;
	}
	if (comparison == i)
		return (0);
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

char	**line_modifier(char *str)
{
	char	**list;
	char 	*key;
	char	*val;
	int		i;
	int		k;
	int 	val_start;

	k = 0;
	i = 0;
	list = malloc(2 * sizeof(char *));
	key = malloc(ft_len(str) * sizeof(char));
	val = malloc(ft_len(str) * sizeof(char));
	
	while ('0' <= str[i] && str[i] <= '9')
	{
		key[i] = str[i];
		i++;
	}
	key[i] = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == ':')
		i++;
	else
		return (0);
	val_start = i;
	while (str[i])
	{
		if (str[i] == ' ' && str[i])
		{
			i++;
			while (str[i] == ' ' && str[i])
			{
				str[i] = -1;
				i++;
			}
		}
		i++;
	}
	while(str[val_start])
	{
		if (str[val_start] != -1 && str[val_start] && (str[val_start] >= 32 && str[val_start] <= 126))
		{
			val[k] = str[val_start];
			k++;
		}
		val_start++;
	}
	val[k] = 0;
	// printf("LINEMODIF: \nkey %s , val: %s \n\n", key, val);
	list[0] = key;
	list[1] = val;
	return (list);
}