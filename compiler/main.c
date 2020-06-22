#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		idx;
	char	*content;
	char	**result;

	idx = 1;
	result = (char **)malloc(sizeof(char *) * (argc + 3));
	result[argc] = 0;
	result[0] = "/usr/bin/gcc";
	result[1] = "-o";
	result[2] = "program";
	while (idx < argc)
	{
		content = translate(argv[idx]);
		result[idx + 2] = print_file(content);
		free(content);
		idx++;
	}
	execv("/usr/bin/gcc", result);
	return (0);
}
