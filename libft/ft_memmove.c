/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 08:55:58 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/07 16:06:39 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*cdst;
	const unsigned char		*csrc;

	cdst = dst;
	csrc = src;
	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		csrc += len;
		cdst += len;
		while (len--)
			*--cdst = *--csrc;
	}
	else
		while (len--)
			*cdst++ = *csrc++;
	return (dst);
}
