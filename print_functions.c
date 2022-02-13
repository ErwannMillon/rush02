#include "ft_includes.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	int	f;
	int	k;

	k = 0;
	f = 0;
	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		k++;
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!(s1[i] == s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	if (!(s1[i] == s2[i]))
		return (s1[i] - s2[i]);
	return (0);
}

char	*hundreds(char	digit, pair **double_array)
{
	pair	*array;
	char	*result;
	int		i;
	int		j;
	char *hundred;
	char compare[2];

	hundred = "100";
	compare[0] = digit;
	compare[1] = 0;
	array = *double_array;
	j = 0;
	i = 0;
	//while (array[i].power != -1)
	//{
	//	printf("Key: %s, compare: %s \n", array[i].key, compare);
	//	i++;
	//}
	while (array[i].power != -1)
	{
		if (ft_strcmp(array[i].key, compare) == 0)
		{
			//printf("Key: %s, compare: %s \n", array[i].key, compare);
			break;
		}
		i++;
	}
	while (array[j].power != -1)
	{
		if (ft_strcmp(array[j].key, hundred) == 0)
		{
			break;
		}
		j++;
	}
	int x = ft_len(array[i].value) + ft_len(array[j].value) + 2;
	//printf("len %d \n", x );
	result = malloc((ft_len(array[i].value) + ft_len(array[j].value) + 2) * sizeof(char));
	ft_strcat(result, array[i].value);
	ft_strcat(result, array[j].value);
	printf("%s", result);
	return (result);
}

char	*tens(char digit, char teens, pair **double_array)
{
	char	*result;
	pair	*array;
	int		i;
	char	compare[3];
	array = *double_array;
	i = 0;

	compare[0] = digit;
	if (digit == '1' && teens != 'n')
	{
		compare[1] = teens;
		compare[2] = 0;
	}
	else
	{
		compare[1] = '0';
		compare[2] = 0;
	}

	while (array[i].power != -1)
	{
		if (ft_strcmp(array[i].key, compare) == 0)
		{
			//printf("Key: %s, compare: %s \n", array[i].key, compare);
			break;
		}
		i++;
	}
	int x = ft_len(array[i].value) + 2;
	// printf("len %d \n", x );
	result = malloc(x * sizeof(char));
	ft_strcat(result, array[i].value);
	printf("%s", result);
	return (result);

}

char	*ones(char digit, pair **double_array)
{
	char	*result;
	pair	*array;
	int		i;
	char	compare[3];
	array = *double_array;
	i = 0;

	compare[0] = digit;
	compare[1] = 0;

	while (array[i].power != -1)
	{
		if (ft_strcmp(array[i].key, compare) == 0)
		{
			//printf("Key: %s, compare: %s \n", array[i].key, compare);
			break;
		}
		i++;
	}
	int x = ft_len(array[i].value) + 2;
	// printf("len %d \n", x );
	result = malloc(x * sizeof(char));
	ft_strcat(result, array[i].value);
	printf("%s", result);
	return (result);

}