/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:06:00 by maginist          #+#    #+#             */
/*   Updated: 2019/03/22 09:13:44 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_words(char const *s, char c)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (j == 0)
				count++;
			j = 1;
		}
		else
			j = 0;
		i++;
	}
	return (count);
}

static char		**ft_split_malloc(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	int		words;
	char	**tab;

	words = ft_nbr_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < words && s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + len] != c && s[i + len])
			len++;
		if (!(tab[j] = ft_strsub(s, i, len)))
			return (0);
		i = i + len;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_split_malloc(s, c));
	return (NULL);
}
