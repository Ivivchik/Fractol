/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:03:10 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/10 23:00:17 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int			s;
	int			sign;
	int			nb;
	char		*a;

	sign = 0;
	nb = n;
	s = 1;
	if (n < 0)
		sign = 1;
	while ((nb /= 10))
		s++;
	a = ft_strnew(s + sign);
	if (a == NULL)
		return (NULL);
	if (sign)
		a[0] = '-';
	while (s--)
	{
		a[s + sign] = (sign ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (a);
}
