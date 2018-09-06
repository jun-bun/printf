/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:27:11 by juwong            #+#    #+#             */
/*   Updated: 2018/09/05 18:53:50 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		format_precision(t_arg *arg, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	if (arg->precision == 0 && ft_atoi(arg->format) == 0)
	{
		arg->size = 0;
		return ;
	}
	else if (arg->precision == -1 || (size_t)arg->precision < arg->size ||
		!(ft_strchr("oOuUxXbBp", c)))
		return ;
	str = ft_strnew(arg->precision);
	while (i < (size_t)arg->precision)
	{
		str[i] = (i + arg->size) < (size_t)arg->precision ? '0' :
		arg->format[i + arg->size - arg->precision];
		i++;
	}
	arg->size = arg->precision;
	free(arg->format);
	arg->format = str;
}

static void		format_hash(t_arg *arg, char c)
{
	char	*s;

	if (arg->alternate == -1)
		return ;
	if (ft_strchr("oO", c))
	{
		s = ft_strjoin("0", arg->format);
		arg->size += 1;
	}
	else if (ft_strchr("xXp", c))
	{
		s = ft_strjoin("0x", arg->format);
		arg->size += 2;
	}
	else if (ft_strchr("bB", c))
	{
		s = ft_strjoin("0b", arg->format);
		arg->size += 2;
	}
	else
		return ;
	free(arg->format);
	arg->format = s;
}

static void		format_padding(t_arg *arg, char c)
{
	char	*s;
	char	padding;

	padding = (arg->zero && arg->align != 'l' && arg->precision == -1) ?
	'0' : ' ';
	if (padding == ' ')
		format_hash(arg, c);
	if (ft_strchr("xXpbB", c) && padding == '0'
		&& (size_t)arg->width >= arg->size && arg->alternate == 1)
		arg->width -= 2;
	if (arg->width > (int)arg->size)
	{
		s = ft_strnew(arg->width);
		ft_memset(s, padding, (size_t)arg->width);
		if (arg->align == 'l')
			ft_memcpy(s, arg->format, arg->size);
		else
			ft_strcpy(&s[arg->width - arg->size], arg->format);
		arg->size = arg->width;
		free(arg->format);
		arg->format = s;
	}
	if (padding == '0')
		format_hash(arg, c);
}

void			parse_unum(char c, t_arg *arg, va_list ap)
{
	uintmax_t	*num;

	num = (uintmax_t *)malloc(sizeof(uintmax_t));
	num = get_unum(c, arg, ap, num);
	if (ft_strchr("xXbB", c))
		arg->alternate = *num == 0 ? -1 : arg->alternate;
	getbase(arg, c);
	arg->format = uintmax_toa_base(num, arg);
	arg->size = ft_strlen(arg->format);
	format_precision(arg, c);
	format_padding(arg, c);
	if (c == 'X' || c == 'B')
		ft_striter2(arg->format, ft_toupper);
	free(num);
}

uintmax_t		*get_unum(char c, t_arg *arg, va_list ap, uintmax_t *num)
{
	if (c == 'O' || c == 'U')
	{
		arg->length = l;
		num = get_unum(c + 32, arg, ap, num);
	}
	else if (c == 'p')
	{
		arg->alternate = 1;
		arg->length = p;
		num = get_unum('x', arg, ap, num);
	}
	else if (arg->length == l || arg->length == p)
		*num = (unsigned long)va_arg(ap, unsigned long);
	else if (arg->length == hh)
		*num = (unsigned char)va_arg(ap, unsigned int);
	else if (arg->length == h)
		*num = (unsigned short)va_arg(ap, unsigned int);
	else if (arg->length == ll)
		*num = (unsigned long long)va_arg(ap, unsigned long long);
	else if (arg->length == z)
		*num = (size_t)va_arg(ap, size_t);
	else if (arg->length == j)
		*num = (uintmax_t)va_arg(ap, uintmax_t);
	else
		*num = (unsigned int)va_arg(ap, unsigned int);
	return (num);
}
