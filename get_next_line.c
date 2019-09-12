/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:29:20 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/12 18:45:19 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Search node with coherent fd or create new
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
 * Deletes old part of node data plus \n
*/

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
		return (1);
	}
	else
	{
		free(curr->content);
		curr->content = 0;
		return (0);
	}
}

/*
 * Find substring to \n and get it in the line
*/

static int			get_line(t_rfile *curr, char **line)
{
	size_t				i;
	char				*new;

	i = 0;
	if (!(curr->content))
		return (0);
	while ((curr->content)[i] != '\n' && (curr->content)[i])
		i++;
	new = ft_strnew(i + 1);
	if (!new)
		return (-1);
	ft_strncpy(new, curr->content, i);
	new[i] = '\0';
	*line = new;
	return (del_content(curr, i, ft_strlen(curr->content) - i));
}

/*
 * Create new string
*/

static char			*string_create(t_rfile *node, size_t n)
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
	return (new);
}

/*
 * Call searching node, filling node and cleaning node
*/

int					get_next_line(const int fd, char **line)
{
	static t_rfile	*node;
	char			buff[BUFF_SIZE + 1];
	size_t			n;
	char			*new;

	n = 0;
	new = 0;
	if (!line)
		return (-1);
	if (!(node = search_node(node, fd)))
		return (-1);
	while ((n = read(fd, buff, BUFF_SIZE)))
	{
		buff[n] = '\0';
		new = string_create(node, n);
		if (!new)
			return (-1);
		ft_strcat(new, buff);
		node->content = new;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (get_line(node, line));
}
