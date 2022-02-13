
#include "ft_includes.h"

int main(void)
{
	char c[22] = "20    :     vin   ght";
	pair *array = malloc(42 * sizeof(pair));
	pair **reference = &array;
	int i = 0;
	int a = verify_line(c);
		char **s = line_modifier(c);
	ft_parse("refdict.txt", reference);
	//printf("Key: %s, Value: %s, Power: %d \n", array[i]->key, array[i]->value, array[i]->power);

	while (i < 42)
	{
		printf("Key: %s, Value: %s, Power: %d \n", array[i].key, array[i].value, array[i].power);
		i++;
	}
	//  hundreds('5', &array);
	//  tens('1', '6', &array);
	// ones('9', &array);
	ft_loop("128979585987542745345", reference);
	return(0);
}