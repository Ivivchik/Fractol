/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:12:37 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/01 19:18:08 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*s;

	i = 0;
	a = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		a[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (a + i + 1);
		i++;
	}
	return (NULL);
}
