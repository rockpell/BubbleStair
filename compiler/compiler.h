#ifndef COMPILER_H
# define COMPILER_H
typedef struct	s_point
{
	int			m;
	int			n;
}				point;

char	*translate(char *str);
char	*print_file(char *content, int idx);
#endif
