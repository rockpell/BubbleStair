#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		get_nbr_size(int nbr)
{
	int		len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*print_file(char *content, int nbr)
{
	int		len;
	int		fd;
	int		size;
	int		idx;
	char	*path;

	len = ft_strlen(content);
	size = get_nbr_size(nbr);
	if ((path = (char *)malloc(sizeof(char) * size + 3)) == 0)
		return (0);
	idx = 0;
	while (idx < size)
	{
		path[size - idx - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		idx++;
	}
	ft_strncpy(&(path[size]), ".c", 2);
	path[size + 2] = 0;
	fd = open(path, O_WRONLY | O_CREAT | S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd < 0)
		return (0);
	write(fd, content, len);
	return (path);
}
