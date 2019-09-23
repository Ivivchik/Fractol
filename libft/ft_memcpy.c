/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:16:51 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/04 20:41:11 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*c;

	i = 0;
	a = (unsigned char *)src;
	c = (unsigned char *)dst;
	while (i < n)
	{
		c[i] = a[i];
		i++;
	}
	return (dst);
}
