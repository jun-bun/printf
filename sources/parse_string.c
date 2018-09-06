/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 23:35:17 by juwong            #+#    #+#             */
/*   Updated: 2018/09/05 23:05:44 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	format_precision(t_arg *arg, char c)
{
	char *str;

	if (arg->precision == -1 || arg->precision > (int)arg->size || c == 0)
		return ;
	str = ft_strnew(arg->precision);
	str = ft_strncpy(str, arg->format, (size_t)arg->precision);
	free(arg->format);
	arg->format = str;
	arg->size = ft_strlen(arg->format);
}

static void	format_padding(t_arg *arg, char c)
{
	char *s;
	char padding;

	padding = ' ';
	if (ft_strchr("Ss", c) && (arg->width > (int)arg->size))
	{
		s = ft_strnew(arg->width);
		ft_memset(s, padding, (size_t)arg->width);
		if (arg->align == 'l')
			ft_memcpy(s, arg->format, arg->size);
		else
		{
			ft_strncpy(&s[arg->width - arg->size], arg->format, arg->size);
		}
		arg->size = arg->width;
		free(arg->format);
		arg->format = s;
	}
}

void		parse_string(char c, t_arg *arg, va_list ap)
{
	if (c == 's' && arg->length == l)
		get_str_wchar(c, arg, ap);
	else if (c == 'S')
	{
		arg->length = l;
		get_str_wchar('s', arg, ap);
	}
	else if (c == 's')
		get_str(c, arg, ap);
}

void		get_str(char c, t_arg *arg, va_list ap)
{
	char 	*str;

	if (c == 's')
	{
		if (!(str = va_arg(ap, char *)))
			str = ft_strdup("(null)");
	}
	arg->format = ft_strdup(str);
	arg->size = ft_strlen(arg->format);
	format_precision(arg, c);
	format_padding(arg, c);
}

void		get_str_wchar(char c, t_arg *arg, va_list ap)
{
	wchar_t *str;

	if (c == 'S' || c == 's')
	{
		c = 'S';
	}
	str = va_arg(ap, wchar_t *);
	arg->format = ft_strdup((char *)str);
	arg->size = 2;
	format_precision(arg, c);
	format_padding(arg, c);
}
