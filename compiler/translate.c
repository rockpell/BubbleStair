#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "compiler.h"

void	calculate(char *str, point *pnt)
{
	pnt->m = 0;
	pnt->n = 0;
	while (*str != 0)
	{
		if (*str == 'O')
			pnt->m = (pnt->m + 1) % 10;
		if (*str == 'o')
			pnt->n = (pnt->n + 1) % 12;
		str++;
	}
}

char	*add_char_to_str(char *str, char c)
{
	char	*result;
	int		len;
	int		idx;

	len = ft_strlen(str);
	idx = 0;
	if ((result = (char *)malloc(sizeof(char) * len + 2)) == 0)
		return (str);
	while (str[idx] != 0)
	{
		result[idx] = str[idx];
		idx++;
	}
	result[idx] = c;
	result[idx + 1] = 0;
	free(str);
	return (result);
}

char	*translate(char *str)
{
	char	*result;
	char	*line;
	int		fd;
	point	pnt;
	int		map[10][12] = {
		{0, 48, 49, 50, 51, 52, 33, 34, 35, 36, 37, 38},
		{53, 54, 55, 56, 57, 59, 39, 42, 43, 44, 45, 46},
		{9, 10, 11, 12, 13, 32, 47, 58, 60, 61, 62, 63},
		{-1, -1, -1, -1, -1, -1, 64, 92, 94, 95, 96, 124},
		{40, 41, 91, 93, 123, 125, 126, -1, -1, -1, -1, -1},
		{97, 98, 99, 100, 101, 102, 65, 66, 67, 68, 69, 70},
		{103, 104, 105, 106, 107, 108, 71, 72, 73, 74, 75, 76},
		{109, 110, 111, 112, 113, 114, 77, 78, 79, 80, 81, 82},
		{115, 116, 117, 118, 119, 120, 83, 84, 85, 86, 87, 88},
		{121, 122, -1, -1, -1, -1, 89, 90, -1, -1, -1, -1}
	};

	line = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if ((result = (char *)malloc(sizeof(char) * 1)) == 0)
		return (NULL);
	result[0] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		calculate(line, &pnt);
		if (map[pnt.m][pnt.n] != -1)
			result = add_char_to_str(result, (char)(map[pnt.m][pnt.n]));
		free(line);
		line = 0;
	}
	if (line != 0)
	{
		calculate(line, &pnt);
		if (map[pnt.m][pnt.n] != -1)
			result = add_char_to_str(result, (char)(map[pnt.m][pnt.n]));
		free(line);
		line = 0;
	}
	return (result);
}
