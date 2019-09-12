/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 08:16:41 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/07 15:20:07 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*temp;

	temp = dst;
	if (!dst && !src)
		return (dst);
	while (n-- > 0)
		*(char*)dst++ = *(char*)src++;
	return (temp);
}
