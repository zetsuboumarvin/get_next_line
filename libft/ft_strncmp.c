/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 08:09:35 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/09 14:37:34 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*(unsigned char*)s1 == *(unsigned char*)s2 && *s1 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if ((!*s1 && *(unsigned char*)s1 == *(unsigned char*)s2) || n == 0)
		return (0);
	else
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
