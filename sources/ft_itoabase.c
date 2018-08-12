/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:13:10 by juwong            #+#    #+#             */
/*   Updated: 2018/08/07 16:22:03 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_itoabase(int n, int base)
{
	char			*str;
	int				l;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = ft_intlen(n);
	if (n < 0)
	{
		if (!(str = ft_strnew(++l)))
			return (NULL);
		*str = '-';
		n = -n;
	}
	else if (n >= 0)
	{
		if (!(str = ft_strnew(l)))
			return (NULL);
	}
	while (--l >= 0 && str[l] != '-')
	{
		str[l] = n % base + 48;
		n = n / base;
	}
	return (str);
}