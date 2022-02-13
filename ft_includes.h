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

char	*ones(char digit, pair **double_array);
int		ft_strcmp(char *s1, char *s2);
char	*tens(char digit, char teens, pair **double_array);
char	*hundreds(char	digit, pair **double_array);
char	*ft_strcat(char *dest, char *src);
int		verify_line(char *str);
int		ft_len(char *s);
char	**line_modifier(char *str);
int		ft_add_to_struct(char *str, pair **array);
void	ft_parse(char *file, pair **array);

#endif