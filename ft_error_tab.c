/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:03:08 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/23 14:59:53 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error_tab(char ***str)
{
	ft_sqdel(str);
	ft_error();
}

void	ft_error_tab_str(char ***str, char **str2)
{
	ft_sqdel(str);
	ft_strdel(str2);
	ft_error();
}
