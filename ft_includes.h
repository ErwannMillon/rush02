#ifndef FT_INCLUDES_H
# define FT_INCLUDES_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	pair{
	char	*key;
	char	*value;
	int		power;

}				pair;

int		verify_line(char *str);
int		ft_len(char *s);
char	**line_modifier(char *str);
int		ft_add_to_struct(char *str, pair **array);
void	ft_parse(char *file, pair **array);

#endif