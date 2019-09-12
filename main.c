#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static t_rfile		*create_node(t_rfile *next, int fd)
{
	t_rfile			*new;

	new = (t_rfile*)malloc(sizeof(t_rfile));
	if (!new)
		return (0);
	new->cfd = fd;
	new->next = next;
	new->content = 0;
	return (new);
}

static t_rfile		*search_node(t_rfile *list, int fd)
{
	t_rfile			*new;

	while (list)
	{
		if (list->cfd == fd)
			return (list);
		list = list->next;
	}
	if (!list)
	{
		new = (t_rfile*)malloc(sizeof(t_rfile));
		if (!new)
			return (0);
		new->cfd = fd;
		new->next = 0;
		new->content = 0;
		return (new);
	}
	return (0);
}

static int			del_content(t_rfile *curr, size_t i, size_t n)
{
	char		*new_content;

	if (n)
	{
		new_content = ft_strnew(n);
		if (!new_content)
			return (0);
		ft_strcpy(new_content, &((curr->content)[i + 1]));
		new_content[n] = '\0';
		curr->content = new_content;
		return (2);
	}
	else
	{
		curr->content = 0;
		return (2);
	}
}

static int			get_line(t_rfile *curr, char **line)
{
	size_t				i;
	char				*new;

	i = 0;
	if (!(curr->content))
		return (1);
	while ((curr->content)[i] != '\n' && (curr->content)[i])
		i++;
	new = ft_strnew(i + 1);
	if (!new)
		return (0);
	ft_strncpy(new, curr->content, i);
	new[i] = '\0';
	*line = new;
	return (del_content(curr, i, ft_strlen(curr->content) - i));
}

static int			get_content(t_rfile *curr, int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	size_t			n;
	char			*new;

	while ((n = read(fd, buff, BUFF_SIZE)))
	{
		buff[n] = '\0';
		new = ft_strnew(ft_strlen(curr->content) + n + 1);
		if (!new)
			return (-1);
		ft_strcpy(new, curr->content);
		ft_strcat(new, buff);
		free(curr->content);
		curr->content = new;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (!(n = get_line(curr, line)))
		return (-1);
	else if (n == 1)
		return (0);
	else
		return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_rfile	*node;
	int				n;

	n = 0;
	printf("\t\t\tcheck");
	if (!line)
		return (-1);
	if (!(node = search_node(node, fd)))
		return (-1);
	if ((n = get_content(node, fd, line)) == -1)
		return (-1);
	else if (n == 0)
		return (0);
	else
		return (1);

}

int			main()
{
	t_rfile	*next = 0;
	t_rfile	*new;
	int		fd = 0;
	int		fd1 = 1;
	int		fd2 = 2;
	int		fd3 = 3;
	char	**line;
	char	test1[] = "teststring1\nteststring2\nteststring3";
	int		n;
	t_rfile	*test;
	int		fda;

	n = 0;
	line = (char**)malloc(sizeof(char*));
	(*line) = (char*)malloc(sizeof(char) * 100);
	new = create_node(next, fd);
	test = new;
	test->content = (char*)malloc(sizeof(char) * 100);
	ft_strcpy(test->content, test1);
	printf("check node - %s\n", test->content);
	next = new;
	new = create_node(next, fd1);
	next = new;
	new = create_node(next, fd2);
	next = new;
	new = create_node(next, fd3);
	next = new;
	printf("\nCHECK FOR LIST\n");
	while (next)
	{
		printf("%d\n", next->cfd);
		next = next->next;
	}
	next = new;
	new = search_node(next, fd2);
	printf("\nCHECK FOR SEARCH\n");
	printf("%d\n", new->cfd);

	printf("\nCHECK GET_LINE\n");
	n = get_line(test, line);
	printf("%d\n", n);
	printf("%s\n", *line);
	printf("\n-----\n");
	printf("%s\n", test->content);
	printf("\n-----------------------------\n");
	n = get_line(test, line);
	printf("%d\n", n);
	printf("%s\n", *line);
	printf("\n-----\n");
	printf("%s\n", test->content);
	printf("\n-----------------------------\n");
	n = get_line(test, line);
	printf("%d\n", n);
	printf("%s\n", *line);
	printf("\n-----\n");
	printf("%s\n", test->content);
	printf("\n-----------------------------\n");
	n = get_line(test, line);
	printf("%d\n", n);
	printf("%s\n", *line);
	printf("\n-----\n");
	printf("%s\n", test->content);

	fda = open("get_next_line.c", O_RDONLY);
	printf("\t\t\t111111check");
	while (get_next_line(fda, line) == 1)
	{
		printf("\t\t\t22222check");
//		printf("%s\n", *line);
	}

	return (0);
}
