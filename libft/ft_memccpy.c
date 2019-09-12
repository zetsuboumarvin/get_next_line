/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 08:30:50 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/07 15:27:26 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)dst++ = *(unsigned char*)src;
			return (dst);
		}
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	}
	return (NULL);
}
