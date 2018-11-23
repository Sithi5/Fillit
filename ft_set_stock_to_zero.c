/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stock_to_zero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:13:16 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/21 21:40:00 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_stock_to_zero(t_tetri *stock_tetri)
{
	int	i;

	i = 19;
	while (i-- >= 0)
	{
		stock_tetri->tab[0][i] = 0;
		stock_tetri->tab[1][i] = 0;
	}
}
