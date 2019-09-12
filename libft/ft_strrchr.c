/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:43:39 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/11 11:02:06 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	unsigned char	*temp;
	unsigned char	*result;

	temp = (unsigned char*)s;
	result = NULL;
	while (*temp)
	{
		if (*temp == (unsigned char)c)
			result = temp;
		temp++;
	}
	if (*temp == (unsigned char)c)
		result = temp;
	return ((char*)result);
}
