/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:39:15 by maginist          #+#    #+#             */
/*   Updated: 2018/11/14 15:39:36 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int i;

	i = 0;
	if (((unsigned char*)src) > ((unsigned char*)dst))
	{
		while (i < n)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char*)dst)[n - i - 1] = ((unsigned char*)src)[n - i - 1];
			i++;
		}
	}
	return (dst);
}
