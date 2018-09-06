/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:33:27 by juwong            #+#    #+#             */
/*   Updated: 2018/09/05 19:57:19 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	format_precision(t_arg *arg, char c)
{
	char	*str;
	size_t	i;

	if (!(ft_strchr("dDi", c)))
		return ;
	i = 0;
	if (arg->precision == 0 && ft_atoi(arg->format) == 0)
	{
		arg->size = 0;
		return ;
	}
	if (arg->precision == -1 || arg->precision < (int)arg->size)
		return ;
	str = ft_strnew(arg->precision);
	while (i < (size_t)arg->precision)
	{
		str[i] = (i + arg->size) < (size_t)arg->precision ? '0' :
		arg->format[i + arg->size - (size_t)arg->precision];
		i++;
	}
	arg->size = arg->precision;
	free(arg->format);
	arg->format = str;
}

static void	format_sign(t_arg *arg, char c)
{
	char	*s;
	char	*sign;

	if (!(ft_strchr("dDi", c)))
		return ;
	if (!arg->sign)
		return ;
	sign = ft_strnew(1);
	*sign = arg->sign;
	s = ft_strjoin(sign, arg->format);
	free(sign);
	free(arg->format);
	arg->format = s;
	arg->size++;
}

static void	format_padding(t_arg *arg, char c)
{
	char	*s;
	char	padding;

	padding = (arg->zero && arg->align != 'l' && arg->precision == -1) ?
	'0' : ' ';
	if (ft_strchr("dDi", c) && (arg->width > (int)arg->size))
	{
		s = ft_strnew(arg->width);
		ft_memset(s, padding, (size_t)arg->width);
		if (arg->align == 'l')
			ft_memcpy(s, arg->format, arg->size);
		else
		{
			if (padding == '0' && arg->sign)
			{
				*s = arg->sign;
				ft_strcpy(&s[arg->width - arg->size + 1], (arg->format + 1));
			}
			else
				ft_strcpy(&s[arg->width - arg->size], arg->format);
		}
		arg->size = arg->width;
		free(arg->format);
		arg->format = s;
	}
}

void		parse_num(char c, t_arg *arg, va_list ap)
{
	intmax_t	*num;

	c = (c == 'i') ? 'd' : c;
	num = (intmax_t *)malloc(sizeof(intmax_t));
	num = get_num(c, arg, ap, num);
	arg->format = intmax_toa(num, arg);
	arg->size = ft_strlen(arg->format);
	format_precision(arg, c);
	format_sign(arg, c);
	format_padding(arg, c);
	free(num);
}

intmax_t	*get_num(char c, t_arg *arg, va_list ap, intmax_t *num)
{
	if (c == 'D')
	{
		arg->length = l;
		num = get_num(c + 32, arg, ap, num);
	}
	else if (arg->length == l || arg->length == p)
		*num = (long)va_arg(ap, long);
	else if (arg->length == hh)
		*num = (char)va_arg(ap, int);
	else if (arg->length == h)
		*num = (short)va_arg(ap, int);
	else if (arg->length == ll)
		*num = (long long)va_arg(ap, long long);
	else if (arg->length == z)
		*num = (size_t)va_arg(ap, size_t);
	else if (arg->length == j)
		*num = (intmax_t)va_arg(ap, intmax_t);
	else
		*num = (int)va_arg(ap, int);
	return (num);
}
