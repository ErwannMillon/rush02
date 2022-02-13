#include "ft_includes.h"
//add reference parameter for powers
void ft_loop(char *str, pair **double_array)
{
	int index;
	int i;
	pair *array;
	int k;
	int power;
	power = -1;
	k = 0;
	i = 0;
	int triplet;
	array = *double_array;
	index = ft_len(str);
	triplet = index % 3;
	while (i < ft_len(str))
	{
		power = -1;
		//printf("Index : %d", index);
		if (index % 3 == 0)
		{
			hundreds(str[i], double_array);
		}
		else if (index % 3 == 2)
		{
			if (str[i] == '1')
			{
				tens(str[i], str[i + 1], double_array);
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
			if (index > 3)
			{
				// printf(" index : %d _\n", index);
				k = 0;
				while (array[k].power <= index)
				{
					if (index >= array[k].power && array[k].power > 3)
					{
						power = k;
						
						// printf("\n%d found k: va; is : %s\n", power,array[power].value );
						//printf("Key: %s, compare: %s \n", array[i].key, compare);
					}
					k++;
				}
				printf("%s", array[power].value);

				// printf("%s", array[power].value);
			}
		}
		//power looping universalize

		index--;
		i++;

		//triplet = index % 3;
	}
}