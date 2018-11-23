/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:40:35 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/23 15:04:04 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_read_file(t_tetri *stock_t, char *fn)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	i = 0;
	if (!(stock_t->tetri = ft_strnew(0)))
		ft_error_struct_str(stock_t, &fn);
	if (!(fd = open(fn, O_RDONLY)))
		ft_error_struct_str_str(stock_t, &fn, &stock_t->tetri);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0 || ++i > 129)
			ft_error_struct_str_str_str(stock_t, &fn, &stock_t->tetri, &line);
		if (!(line = ft_strdjoin(line, "\n")))
			ft_error_struct_str_str_str(stock_t, &fn, &stock_t->tetri, &line);
		if (!(stock_t->tetri = ft_strdjoin(stock_t->tetri, line)))
			ft_error_struct_str_str_str(stock_t, &fn, &stock_t->tetri, &line);
		ft_strdel(&line);
	}
	close(fd);
	ft_maincheck(stock_t->tetri);
	ft_strdel(&line);
	return (ft_swap_nl_to_x(stock_t));
}

t_tetri		*ft_swap_nl_to_x(t_tetri *stock_t)
{
	int	i;

	i = 0;
	while (stock_t->tetri[i + 1])
	{
		if (stock_t->tetri[i] == '\n' && stock_t->tetri[i + 1] == '\n')
			stock_t->tetri[i + 1] = 'x';
		i++;
	}
	return (stock_t);
}

void		ft_cut_to_tetri(char **tetri)
{
	int		i;
	int		j;
	int		y;
	char	*tmp;

	i = -1;
	while (tetri[++i])
	{
		tmp = tetri[i];
		if (!(tetri[i] = ft_strdup(ft_strchr(tetri[i], '#'))))
			ft_error_tab_str(&tetri, &tmp);
		ft_strdel(&tmp);
		j = -1;
		y = 0;
		while (tetri[i][++j])
		{
			if (tetri[i][j] == '#')
				y++;
			if (y == 4)
			{
				tetri[i][j + 1] = '\0';
				break ;
			}
		}
	}
}

char		*ft_set_in_one_line(char *str)
{
	char	**tab;
	char	*s1;
	int		i;

	i = 0;
	if (!(s1 = ft_strnew(0)))
		ft_error_str(&str);
	tab = ft_strsplit(str, '\n');
	while (tab[i])
		s1 = ft_strdjoin(s1, tab[i++]);
	ft_sqdel(&tab);
	ft_strdel(&str);
	return (s1);
}

t_tetri		*ft_parsing(t_tetri *stock_t, int set_order)
{
	int		match;
	int		j;
	int		i;

	i = -1;
	while (stock_t->tetri_block[++i])
	{
		match = 0;
		j = -1;
		while (stock_t->t_base[++j])
		{
			if (ft_strequ(stock_t->tetri_block[i], stock_t->t_base[j]))
			{
				match = 1;
				stock_t->tab[0][set_order] = j;
				stock_t->tab[1][j]++;
				set_order++;
				break ;
			}
		}
		if (match != 1)
			ft_error_tab(&stock_t->tetri_block);
	}
	ft_sqdel(&stock_t->tetri_block);
	return (stock_t);
}
