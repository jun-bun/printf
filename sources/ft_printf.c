/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:05:12 by juwong            #+#    #+#             */
/*   Updated: 2018/08/07 15:19:33 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printf(const char *format, ...);
{
	va_list	ap;
    va_start(ap, format);
	char *i;

	i = format;
	while (*format)
	{
		ft_putstr(i);
		i = va_arg(ap, char*);
	}
	va_end(ap);
	return ()
}

enum s_parse(char *)
{

}