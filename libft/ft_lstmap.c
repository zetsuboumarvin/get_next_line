/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:14:35 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/11 10:58:53 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_all(t_list **head)
{
	t_list		*temp;

	temp = NULL;
	while (*head)
	{
		temp = (*head)->next;
		free((*head)->content);
		free(*head);
		*head = temp;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*head;
	t_list		*prev;

	prev = NULL;
	head = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new = (*f)(lst);
		new = ft_lstnew(new->content, new->content_size);
		if (!prev)
			head = new;
		if (!new)
		{
			free_all(&head);
			return (NULL);
		}
		if (prev)
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (head);
}
