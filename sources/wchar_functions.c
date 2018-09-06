/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:36:19 by juwong            #+#    #+#             */
/*   Updated: 2018/09/06 13:17:22 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		wchar_len(wchar_t chr)
{
	if (chr <= 0x7F)
		return (1);
	else if (chr <= 0x7FF)
		return (2);
	else if (chr <= 0xFFFF)
		return (3);
	else if (chr <= 0x10FFFF)
		return (4);
	return (0);
}

size_t	wcharp_len(wchar_t *in)
{
	size_t len;

	len = 0;
	while (*in)
	{
		len += wchar_len(*in);
		in++;
	}
	return (len);
}

void	wchar_to_str(wchar_t in, char *str)
{
	if (in <= 0x7F)
		str[0] = in;
	else if (in <= 0x7FF)
	{
		str[0] = 192 | (((unsigned int)(in) >> 6) & 63);
		str[1] = 128 | ((unsigned int)(in) & 63);
	}
	else if (in <= 0xFFFF)
	{
		str[0] = 224 | (((unsigned int)(in) >> 12) & 63);
		str[1] = 128 | (((unsigned int)(in) >> 6) & 63);
		str[2] = 128 | ((unsigned int)(in) & 63);
	}
	else if (in <= 0x10FFFF)
	{
		str[0] = 240 | (((unsigned int)(in) >> 18) & 63);
		str[1] = 128 | (((unsigned int)(in) >> 12) & 63);
		str[2] = 128 | (((unsigned int)(in) >> 6) & 63);
		str[3] = 128 | ((unsigned int)(in) & 63);
	}
}

wchar_t	*wchar_dup(wchar_t *in)
{
	wchar_t *str;
	size_t	count;
	size_t	i;

	count = 0;
	while (in[count])
		count++;
	str = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (count + 1));
	i = 0;
	while (i < count)
	{
		str[i] = in[i];
		i++;
	}
	return (str);
}
