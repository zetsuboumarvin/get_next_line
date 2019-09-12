/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:53:30 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/10 13:04:08 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				ldst;
	size_t				lsrc;
	unsigned int		i;

	i = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size <= ldst)
		return (size + lsrc);
	while (*dst)
		dst++;
	while (*src && i < size - ldst - 1)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (lsrc + ldst);
}
