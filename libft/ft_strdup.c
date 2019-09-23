/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:59:52 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/10 21:49:15 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;

	c = (char *)malloc(sizeof(*c) * (ft_strlen(s) + 1));
	if (c == NULL)
		return (NULL);
	return (ft_strcpy(c, s));
}
