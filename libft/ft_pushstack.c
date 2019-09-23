/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:58:06 by hkuhic            #+#    #+#             */
/*   Updated: 2019/02/26 18:59:17 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pushstack(t_stack *stack, int value)
{
	if (stack->top == (int)stack->size - 1)
		return ;
	stack->ar[++stack->top] = value;
}
