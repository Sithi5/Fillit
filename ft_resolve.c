/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:27:27 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/23 11:11:42 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetri(t_tetri *stock_tetri)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		count += stock_tetri->tab[1][i];
		i++;
	}
	return (count);
}

void	ft_set_square(t_tetri *stock_t, int sizeplus)
{
	int i;

	ft_calc_edge(stock_t, sizeplus);
	if (!(stock_t->square = (char **)malloc(sizeof(char *) *
					(stock_t->edge + 1))))
		ft_error();
	stock_t->square[stock_t->edge] = 0;
	i = 0;
	while (i < stock_t->edge)
	{
		if (!(stock_t->square[i] = (char *)malloc(sizeof(char) *
						(stock_t->edge + 1))))
			ft_error();
		stock_t->square[i][stock_t->edge] = 0;
		i++;
	}
	stock_t->square = ft_set_tab_point(stock_t->square, stock_t->edge);
}

int		ft_backtrack(t_tetri *stock_t, int pcs)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (pcs == ft_count_tetri(stock_t))
		return (1);
	while (y < stock_t->edge)
	{
		x = 0;
		while (x < stock_t->edge)
		{
			if (ft_put_tetri_in_sq(stock_t, x, y, pcs))
			{
				if (ft_backtrack(stock_t, pcs + 1))
					return (1);
			}
			ft_del_tetri_in_sq(stock_t->square, pcs + 'A');
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_calc_edge(t_tetri *stock_t, int sizeplus)
{
	int i;

	stock_t->edge = 0;
	i = 0;
	while (i < 19)
	{
		stock_t->edge = stock_t->edge + 4 * stock_t->tab[1][i];
		i++;
	}
	stock_t->edge = ft_sqrt(stock_t->edge) + sizeplus;
}

void	ft_resolve(t_tetri *stock_t)
{
	int		sizeplus;

	sizeplus = 0;
	ft_set_square(stock_t, sizeplus);
	ft_calc_edge(stock_t, sizeplus);
	while (!(ft_backtrack(stock_t, 0)))
	{
		sizeplus++;
		ft_calc_edge(stock_t, sizeplus);
		ft_sqdel(&(stock_t->square));
		ft_set_square(stock_t, sizeplus);
	}
	ft_print_square(stock_t->square);
	ft_sqdel(&(stock_t->square));
}
