/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:29:22 by juwong            #+#    #+#             */
/*   Updated: 2018/09/06 13:09:23 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*wchars_to_str(wchar_t *in)
{
	size_t	len;
	char	*str;
	int		pos;

	len = wcharp_len(in);
	str = ft_strnew(len);
	pos = 0;
	while (*in)
	{
		wchar_to_str(*in, str + pos);
		pos += wchar_len(*in);
		in++;
	}
	return (str);
}
