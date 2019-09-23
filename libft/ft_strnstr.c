/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:07:13 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 17:47:43 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;
	size_t	j;

	a = (char *)hay;
	b = (char *)needle;
	i = ft_strlen(b);
	j = ft_strlen(a);
	if (i == 0)
		return (a);
	if (i > n)
		return (NULL);
	while (n-- >= i && *a != '\0')
	{
		if (ft_strncmp(a, b, i) == 0)
			return (a);
		a++;
	}
	return (NULL);
}
