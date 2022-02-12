#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "includer.h"

typedef struct	pair{
	char	*key;
	char	*value;

}				pair;

void ft_parse(void)
{
	int fd;
	int	i;
	char buffer[80000];
	int bytes_read;

	bytes_read = -2;
	i = 0;
	//change to argv
	fd = open("refdict.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open error \n");
		//write(2, strerror(errno), ft_strllen(strerror(errno)));
		//return (-1);
	}
	while(bytes_read != 0)
	{
		
		bytes_read = read(fd, buffer, 80000);
		i = 0;
		// printf("%s", buffer);
		while (buffer[i])
		{
			//check valid
			//return valid str;
			while (buffer[i] != '\n')
			{
				//create string and pass to validation
				// write(1, &buffer[i], 1);
				i++;
			}
			printf("i = %d\n", i);
			write(1, "\n*\n", 3);
			i++;
		}
		printf("exit first loop");
	}

}
int main (int argc, char **argv)
{
	char	*file;
	if (argc != 2 || argc != 3)
		return (0);

	if (argc == 3)
		file = argv[1];
	else
		file = "en.numbers.dict";
	// ft_parse();
	char *c = "20   :     vinght";
	printf("%d", verify_line(c));
	printf("%s", line_modifier(c));
	return(0);
}