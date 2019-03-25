/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:54:38 by maginist          #+#    #+#             */
/*   Updated: 2018/11/08 17:47:31 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;

	dest = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (dest[i] == (unsigned char)c)
			return (dest + i);
		i++;
	}
	return (NULL);
}
