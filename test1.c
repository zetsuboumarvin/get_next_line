#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int			get_next_line(const int fd, char **line);

int			main()
{
	char	*line;
	int		fda;

	line = (char*)malloc(sizeof(char) * 200);
	fda = open("get_next_line.c", O_RDONLY);
	while (get_next_line(fda, &line) == 1)
		printf("%s\n", line);
	return (0);
}
