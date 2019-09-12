/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:03:53 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/04 15:32:46 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*res;
	char	*temp;

	res = (char*)haystack;
	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			res = (char*)haystack;
			temp = (char*)needle;
			while (*haystack == *needle || *needle == '\0')
			{
				if (*needle == '\0')
					return (res);
				haystack++;
				needle++;
			}
			haystack = res;
			needle = temp;
		}
		haystack++;
	}
	return (NULL);
}
