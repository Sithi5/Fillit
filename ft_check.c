/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:15:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/23 14:57:19 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_ischar(char c)
{
	if (c == '.' || c == '#')
		return (1);
	return (0);
}

void	ft_check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_ischar(str[i]) && str[i] != '\n')
			ft_error_str(&str);
		i++;
	}
}

void	ft_check_end_input(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != '\n')
		ft_error_str(&str);
	if (str[i - 1] == '\n' && str[i - 2] == '\n')
		ft_error_str(&str);
}

int		ft_count_nb_line(char *str)
{
	int i;
	int nbline;

	nbline = 0;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == '\n')
			nbline++;
		i--;
	}
	return (nbline);
}

void	ft_check_input(char *str)
{
	int i;
	int	nbline;
	int x;

	i = -1;
	x = 0;
	nbline = 0;
	while (str[++i])
	{
		if (nbline % 5 == 0 && nbline != 0)
			nbline++;
		if (ft_ischar(str[i]))
			x++;
		if (str[i] == '\n' && x == 4)
		{
			nbline++;
			x = 0;
		}
		else if (x > 4)
			ft_error_str(&str);
	}
	if ((nbline + 1) % 5 != 0)
		ft_error_str(&str);
	if (nbline != ft_count_nb_line(str))
		ft_error_str(&str);
}
