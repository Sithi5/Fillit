/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:53:25 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/23 04:01:27 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (s1)
	{
		while (s1[i])
			i++;
		if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		ft_memcpy(s2, s1, i);
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
