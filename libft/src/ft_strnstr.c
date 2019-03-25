/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:34:15 by maginist          #+#    #+#             */
/*   Updated: 2018/11/09 15:06:55 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*nee;

	i = 0;
	j = 0;
	hay = (char*)haystack;
	nee = (char*)needle;
	if (nee[0] == '\0')
		return (hay);
	while (hay[i] && i < len)
	{
		if (nee[0] == hay[i])
			while (nee[j] == hay[i + j] && i + j < len)
			{
				if (nee[j + 1] == '\0')
					return (&(hay[i]));
				j++;
			}
		i++;
		j = 0;
	}
	return (NULL);
}
