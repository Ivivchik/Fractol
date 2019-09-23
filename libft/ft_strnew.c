/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:26:13 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 18:53:04 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *a;

	if (!(a = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(a, '\0', size + 1);
	return (a);
}
