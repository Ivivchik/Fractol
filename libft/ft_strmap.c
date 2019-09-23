/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:00:08 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 18:19:56 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*a;
	size_t	i;

	if (s == NULL || *f == NULL)
		return (NULL);
	else
	{
		a = ft_strnew(ft_strlen(s));
		if (a == NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			a[i] = f(s[i]);
			i++;
		}
		return (a);
	}
}
