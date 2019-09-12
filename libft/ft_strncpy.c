/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:12:56 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/04 13:18:17 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*temp;

	temp = dst;
	while (*src && len > 0)
	{
		*dst++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*dst++ = '\0';
		len--;
	}
	return (temp);
}
