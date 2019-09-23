/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:12:09 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 18:45:00 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (s == NULL)
		return (NULL);
	else
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			return (ft_strnew(0));
		j = i;
		while (s[j] != '\0')
			j++;
		j--;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		return (ft_strsub(s, i, j - i + 1));
	}
}
