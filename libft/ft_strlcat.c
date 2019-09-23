/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:13:24 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/10 21:58:47 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*a;
	char		*s;
	size_t		i;
	size_t		j;

	if (!(a = (char *)ft_memchr(dst, '\0', size)))
		return (size + ft_strlen(src));
	s = (char *)src;
	a = (char *)dst;
	i = ft_strlen(dst);
	j = i + ft_strlen(s);
	a = a + i;
	while (i < size - 1 && *s)
	{
		*a = *s;
		i++;
		a++;
		s++;
	}
	*a = '\0';
	return (j);
}
