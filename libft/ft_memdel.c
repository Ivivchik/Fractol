/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:58:24 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 17:20:49 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap == NULL || *ap == NULL)
		return ;
	else
	{
		free(*ap);
		*ap = NULL;
	}
}
