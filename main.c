/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@41.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:21:25 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/23 14:33:21 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_main_parsing(char **av, t_tetri *stock_t)
{
	char *tmp;

	ft_set_stock_to_zero(stock_t);
	stock_t = ft_read_file(stock_t, av[1]);
	tmp = ft_set_in_one_line(stock_t->tetri);
	stock_t->tetri_block = ft_strsplit(tmp, 'x');
	ft_strdel(&tmp);
	ft_cut_to_tetri(stock_t->tetri_block);
	ft_parsing(stock_t, 0);
	return (stock_t);
}

void	ft_maincheck(char *str)
{
	ft_check_char(str);
	ft_check_end_input(str);
	ft_check_dim(str, -1, 1, 0);
	ft_check_dim2(str);
	ft_check_input(str);
}

int		main(int ac, char **av)
{
	t_tetri	*stock_t;

	if (ac != 2)
		ft_error();
	if (!(stock_t = (t_tetri *)malloc(sizeof(t_tetri))))
		ft_error_struct(stock_t);
	stock_t->t_base = ft_init_tetri_base();
	ft_resolve(ft_main_parsing(av, stock_t));
	free(stock_t->t_base);
	free(stock_t);
	return (0);
}
