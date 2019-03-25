/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:19:14 by maginist          #+#    #+#             */
/*   Updated: 2019/03/22 09:10:04 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = NULL;
	if (!(str = (char*)malloc(sizeof(char*) * size)))
		return (NULL);
	if (!(ft_memset(str, 0, size)))
		return (NULL);
	return (str);
}
