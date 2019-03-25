/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:19:42 by maginist          #+#    #+#             */
/*   Updated: 2018/11/09 15:06:17 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*hay;
	char	*nee;

	i = 0;
	j = 0;
	hay = (char*)haystack;
	nee = (char*)needle;
	if (nee[0] == '\0')
		return (hay);
	while (hay[i])
	{
		if (hay[i] == nee[0])
			while (nee[j] == hay[i + j])
			{
				if (nee[j + 1] == '\0')
					return (&(hay[i]));
				j++;
			}
		i++;
		j = 0;
	}
	return (0);
}
