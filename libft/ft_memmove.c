/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:39:54 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/10 23:01:17 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*a;
	const char	*s;

	a = (char *)dst;
	s = (char *)src;
	if (src >= dst)
		dst = ft_memcpy(dst, src, n);
	else
	{
		a = a + n;
		s = s + n;
		while (n)
		{
			*--a = *--s;
			n--;
		}
	}
	return (dst);
}
