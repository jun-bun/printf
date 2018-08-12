/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 21:33:01 by juwong            #+#    #+#             */
/*   Updated: 2018/08/08 23:26:26 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>

enum	e_length
{
	none,
	hh,
	h,
	l,
	ll,
	L,
	q,
	j,
	z,
	t,
	p
};

enum	e_format
{
	s,
	S,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	c,
	C
};

typedef struct		s_arg
{
    va_list ap;
    char    *format;
    int     min_len;
    int     precision;
}					t_arg;

int		ft_printf(const char *format, ...);
char	*s_parse(const char *str);
char	*ft_itoabase(int n, int base);

#endif