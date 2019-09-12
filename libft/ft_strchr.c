/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:37:29 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/11 11:07:11 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	unsigned char	*temp;

	temp = (unsigned char*)s;
	while (*temp)
	{
		if (*temp == (unsigned char)c)
			return ((char*)temp);
		temp++;
	}
	if (*temp == (unsigned char)c)
		return ((char*)temp);
	return (NULL);
}
