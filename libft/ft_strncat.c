/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:11:42 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/04 15:05:31 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && j < n)
	{
		dst[j + i] = src[j];
		j++;
	}
	dst[j + i] = '\0';
	return (dst);
}
