/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 19:13:28 by juwong            #+#    #+#             */
/*   Updated: 2018/09/09 20:08:48 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*parse_length(t_arg *arg, char *str)
{
	if (*str == 'h' && *(str + 1) == 'h')
	{
		arg->length = hh;
		return (str + 2);
	}
	else if (*str == 'l' && *(str + 1) == 'l')
	{
		arg->length = ll;
		return (str + 2);
	}
	else if (*str == 'h')
		arg->length = h;
	else if (*str == 'l')
		arg->length = l;
	else if (*str == 'j')
		arg->length = j;
	else if (*str == 'z')
		arg->length = z;
	return (++str);
}

char	*parse_width_precision(t_arg *arg, char *str, va_list ap)
{
	if (*str == '*')
	{
		arg->width = (int)va_arg(ap, int);
		return (++str);
	}
	else if (ft_isdigit(*str))
	{
		arg->width = ft_atoi((const char*)str);
		return (str += (ft_intlen(arg->width)));
	}
	else if (*str == '.')
	{
		if (ft_isdigit(*(++str)))
		{
			arg->precision = ft_atoi((const char*)str);
			return (str += (ft_intlen(arg->precision)));
		}
		else if (*str == '*')
		{
			arg->precision = (int)va_arg(ap, int);
			return (++str);
		}
		else
			arg->precision = 0;
	}
	return (str);
}

char	*parse_flag(t_arg *arg, char *str)
{
	if (*str == '-')
		arg->align = 'l';
	else if (*str == '+')
		arg->sign = '+';
	else if (*str == ' ')
		arg->sign = arg->sign == '+' ? '+' : ' ';
	else if (*str == '0')
		arg->zero = 1;
	else if (*str == '#')
		arg->alternate = 1;
	return (++str);
}
