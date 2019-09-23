/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:04:14 by hkuhic            #+#    #+#             */
/*   Updated: 2019/02/26 19:11:55 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_stack		*ft_createstack(size_t size)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->size = size;
	stack->top = -1;
	stack->ar = (int*)malloc(sizeof(int) * size);
	return (stack);
}
