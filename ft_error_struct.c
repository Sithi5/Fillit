/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:05:04 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/23 15:06:04 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error_struct(t_tetri *stock_t)
{
	free(stock_t);
	ft_error();
}

void	ft_error_struct_tab(t_tetri *stock_t, char ***tab)
{
	ft_sqdel(tab);
	free(stock_t);
	ft_error();
}
