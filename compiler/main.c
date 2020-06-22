#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "compiler.h"

/*
   end  48  49  50  51  52  33  34  35  36  37  38
    53  54  55  56  57  58  39  42  43  44  45  46
     9  10  11  12  13  32  47  59  60  61  62  63
	                        64  92  94  95  96 124
    40  41  91  93 123 125 126
	97  98  99 100 101 102  65  66  67  68  69  70
   103 104 105 106 107 108  71  72  73  74  75  76
   109 110 111 112 113 114  77  78  79  80  81  82
   115 116 117 118 119 120  83  84  85  86  87  88
   121 122                  89  90
  m:10 n:12
*/
int	main(int argc, char **argv)
{
	int		idx;
	char	*content;
	char	**result;

	idx = 1;
	if ((result = (char **)malloc(sizeof(char *) * (argc + 3))) == 0)
		return (0);
	result[argc] = 0;
	result[0] = "/usr/bin/gcc";
	result[1] = "-o";
	result[2] = "program";
	while (idx < argc)
	{
		content = translate(argv[idx]);
		if (content == NULL)
		{
			printf("file open fail\n");
			exit(0);
		}
		//result[idx + 2] = print_file(content);
		free(content);
		idx++;
	}
	//execv("/usr/bin/gcc", result);
	return (0);
}
