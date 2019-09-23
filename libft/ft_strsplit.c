/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:19:28 by hkuhic            #+#    #+#             */
/*   Updated: 2018/12/18 19:05:40 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_words(const char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			len++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (len);
}

static int	ft_len(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (!i)
		i++;
	return (i);
}

static char	**ft_adel(char **a, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(a[i]);
	free(a);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		i;
	int		in;

	in = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	a = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (a == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(a[in] = ft_strsub(&s[i], 0, ft_len(&s[i], c))))
				return (ft_adel(a, in));
			i = i + ft_len(&s[i], c);
			in++;
		}
	}
	a[in] = NULL;
	return (a);
}
