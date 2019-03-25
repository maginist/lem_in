/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:29:42 by maginist          #+#    #+#             */
/*   Updated: 2018/11/08 17:47:57 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ch1;
	unsigned char	*ch2;

	ch1 = (unsigned char*)s1;
	ch2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (ch1[i] == ch2[i])
		{
			i++;
			n--;
		}
		else
			return (ch1[i] - ch2[i]);
	}
	return (0);
}
