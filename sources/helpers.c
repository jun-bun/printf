/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:41:20 by juwong            #+#    #+#             */
/*   Updated: 2018/09/04 23:53:44 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_striter2(char *s, int (*f)(int))
{
	if (!s || !f)
		return ;
	while (*s)
	{
		*s = f(*s);
		s++;
	}
}

size_t	ft_intmax_tlen(intmax_t c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

int		ishexzero(char *s)
{
	while (*s)
	{
		if (*s != '0')
			return (0);
		s++;
	}
	return (1);
}
