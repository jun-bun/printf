/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:29:22 by juwong            #+#    #+#             */
/*   Updated: 2018/09/06 13:04:22 by juwong           ###   ########.fr       */
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

void    	get_str_wchar(char c, t_arg *arg, va_list ap)
{
	wchar_t *wstr;
	char	*str;

	if (c != 'S' && arg->length != l)
		return;
	wstr = va_arg(ap, wchar_t *);
	if (!wstr)
		str = ft_strdup("(null");
	else
		str = wchars_to_str(wstr);
	
	arg->size = ft_strlen(str);
	arg->format = ft_strdup(str);
//	write(1, str, arg->size);
//	ft_memcpy(arg->format, str, arg->size + 1);
}