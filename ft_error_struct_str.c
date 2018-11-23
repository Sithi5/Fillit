/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_struct_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:11:03 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/23 15:05:29 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error_struct_str(t_tetri *stock_t, char **str)
{
	ft_strdel(str);
	free(stock_t);
	ft_error();
}

void	ft_error_struct_str_str(t_tetri *stock_t, char **str, char **str2)
{
	ft_strdel(str);
	ft_strdel(str2);
	free(stock_t);
	ft_error();
}

void	ft_error_struct_str_str_str(t_tetri *stock_t, char **str, char **str2
		, char **str3)
{
	ft_strdel(str);
	ft_strdel(str2);
	ft_strdel(str3);
	free(stock_t);
	ft_error();
}
