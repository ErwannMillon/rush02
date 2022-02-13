#include "ft_includes.h"

int		ft_add_to_struct(char *str, pair **array)
{
	static int	array_pos = 0;
	char		**list;
	int			i;
	int			j;
	pair 		new;

	j = 0;
	i = 0;
	char *tmp;
	//printf("ADDSTRUCT: \nkey %s , val: %s \n\n", list[0], list[1]);
	// printf("topaddstruct %s", tmp);
	while (str[i] && str[i] != '\n')
		i++;
	//printf("\n String: %d", str[i]);
	
	if (!(str[i] == '\n' || str[i] == EOF || str[i] == 0))
	{
		printf("failed");
		return(0);
	}
	else
	{
		//printf("copying");
		tmp = malloc(i + 1 * sizeof(char));
		while (j < i)
		{
			tmp[j] = str[j];
			j++;
		}
		tmp[j] = 0;
	}
	//printf("%s \n", tmp);
	if (!(verify_line(tmp)))
	{
		printf("invalid string: %s \n", tmp);
		return (0);
	}
	//printf("%s\n", tmp);
	list = line_modifier(tmp);
	//printf("ADDSTRUCT: \nkey %s , val: %s \n\n", list[0], list[1]);
	new.key = list[0];
	new.value = list[1];
	new.power = ft_len(list[0]) - 1;
	printf("\nnew.key:%s new.value,: %s , arrapos: %d\n", new.key, new.value, array_pos);
	array[0][array_pos] = new;
	array_pos++;
	return (1);
}

void ft_parse(char *file, pair **array)
{
	int fd;
	int linestart;
	int	i;
	char buffer[30000];
	int bytes_read;
	int line_no = 0;
	linestart = 0;
	bytes_read = -2;
	i = 0;
	//change to argv
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("open error \n");
		//write(2, strerror(errno), ft_strllen(strerror(errno)));
		//return (-1);
	}
	while(bytes_read != 0)
	{
		
		bytes_read = read(fd, buffer, 30000);
		i = 0;
		printf("reintializeing\n");
		while (buffer[i] && bytes_read > 0 && buffer[i] != EOF)
		{
			//check valid
			//return valid str;
			if (buffer[i - 1] == '\n' && buffer[i] == '\n' && i != 0)
			{
				i++;
				//prevent overflow
				continue;
			}
			ft_add_to_struct(&buffer[i], array);
			while (buffer[i] != '\n' && i < bytes_read && buffer[i + 1] != EOF)
				i++;
			if (buffer[i] == 0 || buffer[i] == EOF)
				break;
			i++;
		}
		//printf("%s finalline \n", &buffer[linestart + 1]);
		//ft_add_to_struct(&buffer[linestart + 1], array);
	}
	// printf("back in main\n");
}