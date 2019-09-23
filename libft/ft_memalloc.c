/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:32:11 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 18:53:14 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*a;

	i = 0;
	a = (void *)malloc(sizeof(void *) * size);
	if (a == NULL)
		return (NULL);
	while (i < size)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}
