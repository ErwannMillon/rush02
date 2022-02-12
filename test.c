#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	pair{
	char	*key;
	char	*value;

}				pair;

void ft_parse(void)
{
	int fd;
	int	i;
	char buffer[4096];
	int bytes_read;

	bytes_read = -2;
	i = 1;
	//change to argv
	fd = open("refdict.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open error \n");
		//write(2, strerror(errno), ft_strllen(strerror(errno)));
		return (-1);
	}
	while(bytes_read != 0)
	{
		i = 0;
		bytes_read = read(fd, buffer, 4096);
		while (buffer[i] != EOF && buffer[i] != '\n')
		{
			
		}
	}

}
int main (int argc, char **argv)
{
	if (argc == 1)
	write(2, "File name missing.", 19);
if (argc > 2)
	write(2, "Too many arguments.", 19);
	ft_parse();
	return(0);
}