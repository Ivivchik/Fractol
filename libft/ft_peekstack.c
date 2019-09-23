/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peekstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:13:40 by hkuhic            #+#    #+#             */
/*   Updated: 2019/02/26 19:19:03 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_peekstack(t_stack *stack)
{
	if (stack->top == -1)
		return (-1);
	return (stack->ar[stack->top - 1]);
}