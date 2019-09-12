/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:24:46 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/09 17:13:52 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	j = len - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] && len > 0)
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > 0 && len > 0)
		j--;
	if (j <= i || !len)
		len = 0;
	else
		len = j - i + 1;
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strncpy(new, &s[i], len);
	new[len] = '\0';
	return (new);
}
