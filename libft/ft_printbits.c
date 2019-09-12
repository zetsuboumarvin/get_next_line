/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:29:20 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/10 14:30:35 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printbits(unsigned char octet)
{
	int	mask;

	mask = 256;
	while (mask >>= 1)
		(octet & mask) ? ft_putchar('1') : ft_putchar('0');
}
