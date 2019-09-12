/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:23:51 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/07 13:23:54 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intlen(int n)
{
	int				len;
	unsigned int	num;

	len = 0;
	if (n < 0)
	{
		num = 0 - (unsigned)n;
		len++;
	}
	else
		num = (unsigned)n;
	while (num > 9)
	{
		num /= 10;
		len++;
	}
	return (len + 1);
}

char			*ft_itoa(int n)
{
	unsigned int		num;
	char				*s;
	int					i;

	i = intlen(n);
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n < 0)
	{
		num = 0 - (unsigned)n;
		s[0] = '-';
	}
	else
		num = (unsigned)n;
	while (num > 9)
	{
		s[--i] = num % 10 + '0';
		num /= 10;
	}
	s[--i] = num % 10 + '0';
	return (s);
}
