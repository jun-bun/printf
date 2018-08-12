/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:06:40 by juwong            #+#    #+#             */
/*   Updated: 2018/07/25 13:48:47 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The strrchr() function is identical to strchr(), except it locates the
**last occurrence of c.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	if (*s == c)
		ptr = (char*)s;
	while (*s)
	{
		s++;
		if (*s == c)
			ptr = (char*)s;
	}
	return (ptr);
}
