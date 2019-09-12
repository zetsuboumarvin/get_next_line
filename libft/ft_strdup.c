/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:06:07 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/04 11:41:40 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!new)
		return (0);
	ft_strcpy(new, s1);
	return (new);
}
