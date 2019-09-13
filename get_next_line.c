/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:29:20 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/13 08:03:08 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Search node with coherent fd or create new
*/

static t_rfile		*search_node(t_rfile *list, int fd)
{
	t_rfile			*new;
	t_rfile			*temp;

	temp = list;
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
		new->next = temp;
		new->content = 0;
		return (new);
	}
	return (0);
}

/*
** Find substring to \n and get it in the line
*/

static int			get_line(t_rfile *curr, char **line)
{
	size_t				i;
	char				*new;
	char				*new_content;
	size_t				n;

	i = 0;
	if (!(curr->content))
		return (0);
	while ((curr->content)[i] != '\n' && (curr->content)[i])
		i++;
	new = ft_strnew(i + 1);
	if (!new)
		return (-1);
	ft_strncpy(new, curr->content, i);
	*line = new;
	if ((n = ft_strlen(curr->content) - i - 1))
	{
		new_content = ft_strdup(&((curr->content)[i + 1]));
		if (!new_content)
			return (-1);
		curr->content = new_content;
	}
	else
		curr->content = 0;
	return (1);
}

/*
** Create new string and replace it in node content
*/

static int			string_create(t_rfile *node, size_t n, char *buff)
{
	char		*new;

	new = 0;
	if (!(node->content))
	{
		new = ft_strnew(n + 1);
		if (!new)
			return (0);
	}
	else
	{
		new = ft_strnew(ft_strlen(node->content) + n + 1);
		if (!new)
			return (0);
		ft_strcpy(new, node->content);
		free(node->content);
	}
	ft_strcat(new, buff);
	node->content = new;
	return (1);
}

/*
** Call searching node, filling node and cleaning node
*/

int					get_next_line(const int fd, char **line)
{
	static t_rfile	*node;
	char			buff[BUFF_SIZE + 1];
	size_t			n;

	n = 0;
	if (!line || !(node = search_node(node, fd)))
		return (-1);
	while ((n = read(fd, buff, BUFF_SIZE)))
	{
		buff[n] = '\0';
		if (!string_create(node, n, buff))
			return (-1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	n = get_line(node, line);
	return (n);
}
