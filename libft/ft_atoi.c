/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 08:22:07 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/10 10:51:18 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int				i;
	long int		base;
	int				sign;
	long int		max;

	i = 0;
	base = 0;
	sign = 1;
	max = FT_LONG_MAX / 10;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -sign;
	while (ft_isdigit(s[i]))
	{
		if (sign > 0 && (base > max || (base == max && s[i] > '7')))
			return ((int)FT_LONG_MAX);
		else if (sign < 0 && (base > max || (base == max && s[i] > '8')))
			return ((int)FT_LONG_MIN);
		base = base * 10 + s[i] - '0';
		i++;
	}
	return (sign * (int)base);
}
