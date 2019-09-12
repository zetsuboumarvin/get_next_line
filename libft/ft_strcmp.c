/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 08:02:45 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/09 14:35:06 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*(unsigned char*)s1 == *(unsigned char*)s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (!*s1 && *(unsigned char*)s1 == *(unsigned char*)s2)
		return (0);
	else
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
