/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:36:50 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/01 19:13:33 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*c;

	i = 0;
	a = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (i < n)
	{
		if (a[i] != c[i])
			return (a[i] - c[i]);
		i++;
	}
	return (0);
}
