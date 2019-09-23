/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:45:26 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/14 19:38:26 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*a;

	while (*alst)
	{
		a = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = a;
	}
	*alst = NULL;
	return ;
}
