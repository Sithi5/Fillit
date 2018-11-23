/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:17:45 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/23 12:01:18 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_init_tetri_base(void)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 20)))
		return (0);
	tab[0] = "####";
	tab[1] = "#...#...#...#";
	tab[2] = "##..##";
	tab[3] = "###...#";
	tab[4] = "#...#..##";
	tab[5] = "#...###";
	tab[6] = "##..#...#";
	tab[7] = "###.#";
	tab[8] = "#.###";
	tab[9] = "#...#...##";
	tab[10] = "##...#...#";
	tab[11] = "##.##";
	tab[12] = "#...##...#";
	tab[13] = "#..###";
	tab[14] = "#...##..#";
	tab[15] = "###..#";
	tab[16] = "#..##...#";
	tab[17] = "##...##";
	tab[18] = "#..##..#";
	tab[19] = NULL;
	return (tab);
}

char	**ft_init_tetri_base_for_put(void)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 20)))
		return (0);
	tab[0] = "####";
	tab[1] = "#+-#+-#+-#";
	tab[2] = "##+--##";
	tab[3] = "###+-#";
	tab[4] = "#+-#+--##";
	tab[5] = "#+-###";
	tab[6] = "##+--#+-#";
	tab[7] = "###+---#";
	tab[8] = "#+---###";
	tab[9] = "#+-#+-##";
	tab[10] = "##+-#+-#";
	tab[11] = "##+---##";
	tab[12] = "#+-##+-#";
	tab[13] = "#+--###";
	tab[14] = "#+-##+--#";
	tab[15] = "###+--#";
	tab[16] = "#+--##+-#";
	tab[17] = "##+-##";
	tab[18] = "#+--##+--#";
	tab[19] = NULL;
	return (tab);
}

char	**ft_set_tab_point(char **square, int square_size)
{
	int i;
	int j;

	i = 0;
	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			square[i][j] = '.';
			j++;
		}
		square[i][j] = 0;
		i++;
	}
	return (square);
}
