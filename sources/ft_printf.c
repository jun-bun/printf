/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:05:12 by juwong            #+#    #+#             */
/*   Updated: 2018/09/06 17:49:49 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	int			bytes;

	va_start(ap, format);
	str = (char *)format;
	bytes = 0;
	while (*str)
	{
		if (*str == '%')
			str = s_parse(++str, ap, &bytes);
		else
			str = print_until(str, &bytes);
	}
	va_end(ap);
	return (bytes);
}

char	*s_parse(char *str, va_list ap, int *bytes)
{
	t_arg	*arg;

	arg = init_args();
	while (*str)
	{
		if (ft_strchr(" +-#0", *str))
			str = parse_flag(arg, str);
		else if ((ft_isdigit(*str)) || (*str == '.'))
			str = parse_width_precision(arg, str);
		else if (ft_strchr("hljz", *str))
			str = parse_length(arg, str);
		else if (ft_strchr("sSpdDioOuUxXcC%bB", *str))
		{
			str = parse_arg(arg, ap, str);
			break;
		}
		else
			str++;
	}
	write(1, arg->format, arg->size);
	*bytes += (int)arg->size;
	CHECKFREE(arg->format);
	CHECKFREE(arg);
	return (str);
}

char	*parse_arg(t_arg *arg, va_list ap, char *str)
{
	if (*str == 's' || *str == 'S')
		parse_string(*str, arg, ap);
	else if (*str == 'd' || *str == 'D' || *str == 'i')
		parse_num(*str, arg, ap);
	else if (*str == 'p' || *str == 'o' || *str == 'O' || *str == 'u'
	|| *str == 'U' || *str == 'x' || *str == 'X' || *str == 'b' || *str == 'B')
		parse_unum(*str, arg, ap);
	else if (*str == 'c' || *str == 'C')
		parse_c(*str, arg, ap);
	else if (*str == '%')
		parse_percent(*str, arg);
	return (++str);
}

char	*print_until(char *str, int *bytes)
{
	char	*p;
	int		i;

	p = ft_strchr(str, '%');
	if (!p)
		p = ft_strchr(str, '\0');
	i = p - str;
	write(1, str, i);
	*bytes += i;
	return (str + i);
}

t_arg	*init_args(void)
{
	t_arg	*arg;

	arg = (t_arg*)malloc(sizeof(t_arg));
	arg->format = 0;
	arg->size = 0;
	arg->align = 0;
	arg->sign = 0;
	arg->zero = 0;
	arg->alternate = -1;
	arg->width = -1;
	arg->alternate = -1;
	arg->precision = -1;
	arg->base = -1;
	arg->length = none;
	return (arg);
}
