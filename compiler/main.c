#include <stdilb.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		idx;
	char	*content;
	char	**result;

	idx = 1;
	result = (char **)malloc(sizeof(char *) * (argc + 1));
	result[argc] = 0;
	result[0] = "program";
	while (idx < argc)
	{
		content = translate(argv[idx]);
		result[idx] = print_file(content);
		free(content);
		idx++;
	}
	execv("gcc -o", result);
	idx = 0;
	while (idx < argc)
	{
		free(result[idx]);
		idx++;
	}
	free(result);
	return (0);
}
