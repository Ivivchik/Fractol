/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:07:54 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 17:27:24 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char		*a;
	size_t		i;

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
			a[i] = f(i, s[i]);
			i++;
		}
		return (a);
	}
}
