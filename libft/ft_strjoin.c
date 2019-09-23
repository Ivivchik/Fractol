/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:43:40 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 17:40:17 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		l1;
	int		l2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	else
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		s = (char *)malloc(sizeof(*s) * (l1 + l2));
		if (s == NULL)
			return (NULL);
		ft_strcpy(s, s1);
		ft_strcat(s, s2);
		return (s);
	}
}
