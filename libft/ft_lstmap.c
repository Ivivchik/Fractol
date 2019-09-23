/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:24:46 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 19:14:00 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *new;
	t_list *prev;
	t_list *fr;

	if (lst == NULL || *f == NULL)
		return (NULL);
	else
	{
		fr = f(lst);
		if (!(new = ft_lstnew(fr->content, fr->content_size)))
			return (NULL);
		prev = new;
		lst = lst->next;
		while (lst)
		{
			fr = f(lst);
			if (!(new->next = ft_lstnew(fr->content, fr->content_size)))
				return (NULL);
			new = new->next;
			lst = lst->next;
		}
		return (prev);
	}
}
