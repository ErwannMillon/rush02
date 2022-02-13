#include "ft_includes.h"
//add reference parameter for powers
void ft_loop(char *str, pair **double_array)
{
	int		index;
	int		i;
	pair	*array;

	i = 0;
	array = *double_array;
	index = ft_len(str);
	while (i < ft_len(str))
	{
		//printf("Index : %d", index);
		if (index % 3 == 0)
		{
			hundreds(str[i], double_array);
		}
		else if (index % 3 == 2)
		{
			if (str[i] == '1')
			{
				tens(str[i], str [i + 1], double_array);
				index--;
				i++;
			}
			else 
			{
				tens(str[i], 'n', double_array);
			}
		}
		else if (index % 3 == 1)
		{
			ones(str[i], double_array);
		}
		//power looping
		index--;
		i++;
	}

}