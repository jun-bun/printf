/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 20:43:51 by juwong            #+#    #+#             */
/*   Updated: 2018/09/09 19:06:54 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	format_padding(t_arg *arg, char c)
{
	char		*s;
	char		padding;

	padding = ' ';
	if (ft_strchr("cC%", c) && (arg->width > (int)arg->size))
	{
		s = ft_strnew(arg->width);
		ft_memset(s, padding, (size_t)arg->width);
		if (arg->align == 'l')
			ft_memcpy(s, arg->format, arg->size);
		else
		{
			ft_strcpy(&s[arg->width - arg->size], arg->format);
		}
		arg->size = arg->width;
		free(arg->format);
		arg->format = s;
	}
}

void		get_char(char c, t_arg *arg, va_list ap)
{
	int		ch;

	if (c == 'c')
		ch = va_arg(ap, int);
	else
		return ;
	arg->format = ft_strnew(1);
	arg->format[0] = ch;
	arg->size = 1;
	format_padding(arg, 'c');
}

void		get_wchar(char c, t_arg *arg, va_list ap)
{
	wint_t	ch;
	int		len;

	if (c == 'c' || c == 'C')
		ch = va_arg(ap, wint_t);
	else
		return ;
	
	len = wchar_len(ch);
	arg->format = ft_strnew(len);
	wchar_to_str(ch, arg->format);
	/*
	arg->format = ft_strdup((char*)&ch);
	arg->size = ft_strlen(arg->format);
	*/
}

void		parse_c(char c, t_arg *arg, va_list ap)
{
	if (c == 'c' && arg->length == l)
		get_wchar(c, arg, ap);
	else if (c == 'C')
	{
		arg->length = l;
		get_wchar('c', arg, ap);
	}
	else if (c == 'c')
		get_char(c, arg, ap);
}

void		parse_percent(char c, t_arg *arg)
{
	if (c == '%')
	{
		arg->format = ft_strnew(1);
		arg->format[0] = '%';
		arg->size = 1;
		format_padding(arg, '%');
	}
}
