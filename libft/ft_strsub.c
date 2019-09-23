/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:51:25 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 18:45:39 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	if (s == NULL)
		return (NULL);
	else
	{
		sub = ft_strnew(len);
		if (sub == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		return (sub);
	}
}
