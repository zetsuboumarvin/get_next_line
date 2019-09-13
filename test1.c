#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int			get_next_line(const int fd, char **line);

int			main()
{
	char	*line;
	int		fda;
	int		fdb;
	int		fdc;
	int		i;

	i = 0;
	line = (char*)malloc(sizeof(char) * 200);
	fda = open("get_next_line.c", O_RDONLY);
	fdb = open("new.txt", O_RDONLY);
	fdc = open("new1.txt", O_RDONLY);
	if (fdc == -1)
		return (1);
	for (i = 0; i < 10; i++)
	{
		get_next_line(fda, &line);
		printf("%s\n", line);
	}
	while (get_next_line(fdb, &line) == 1)
		printf("%s\n", line);
	while (get_next_line(fda, &line) == 1)
		printf("%s\n", line);
	while (get_next_line(fdc, &line) == 1)
		printf("%s\n", line);
	close(fda);
	close(fdb);
	close(fdc);
	return (0);
}
