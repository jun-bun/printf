/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:40:21 by juwong            #+#    #+#             */
/*   Updated: 2018/09/05 03:21:37 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		getbase(t_arg *arg, char c)
{
	int		base;

	if (c == 'o' || c == 'O')
		base = 8;
	else if (c == 'x' || c == 'X' || c == 'p')
		base = 16;
	else if (c == 'b')
		base = 2;
	else
		base = 10;
	arg->base = base;
	return ;
}

char		*intmax_toa(intmax_t *num, t_arg *arg)
{
	size_t	len;
	char	*ascii;
	int		sign;
	char	*ptr;

	if (*num == 0)
		return (ft_strdup("0"));
	sign = (*num > 0) ? 1 : -1;
	arg->sign = sign > 0 ? arg->sign : '-';
	len = ft_intmax_tlen(*num);
	ascii = ft_strnew(len);
	ptr = ascii;
	while (*num != 0)
	{
		*ascii = (*num % 10) * sign + '0';
		*num = *num / 10;
		ascii++;
	}
	ft_strreverse(ptr);
	return (ptr);
}

char		*uintmax_toa_base(uintmax_t *num, t_arg *arg)
{
	size_t		len;
	uintmax_t	n;
	char		*ascii;
	int			rem;

	len = 0;
	n = *num;
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		n /= arg->base;
		len++;
	}
	ascii = ft_strnew(len);
	while (*num != 0)
	{
		rem = *num % arg->base;
		*ascii = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		*num = *num / arg->base;
		ascii++;
	}
	ft_strreverse(ascii -= len);
	return (ascii);
}
