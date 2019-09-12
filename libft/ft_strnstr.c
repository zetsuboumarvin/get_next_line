/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:37:21 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/09 14:30:40 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search(const char *hay, const char *nee, size_t len,
		unsigned int i)
{
	while (*hay == *nee || *nee == '\0')
	{
		if (*nee == '\0' && i <= len)
			return (1);
		hay++;
		nee++;
		i++;
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*res;
	char			*temp;
	unsigned int	i;

	i = 0;
	res = (char*)haystack;
	if (!*needle)
		return ((char*)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack && i <= len - 1)
	{
		if (*haystack == *needle)
		{
			res = (char*)haystack;
			temp = (char*)needle;
			if (search(haystack, needle, len, i))
				return (res);
			haystack = res;
			needle = temp;
		}
		haystack++;
		i++;
	}
	return (NULL);
}
