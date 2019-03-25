/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:10:02 by maginist          #+#    #+#             */
/*   Updated: 2018/11/14 15:17:18 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnb(int n)
{
	int j;

	j = 0;
	if (n < 0 || n == 0)
		j = 1;
	while (n != 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char		*ft_itoa(int n)
{
	int		j;
	int		neg;
	char	*str;

	neg = 1;
	j = ft_countnb(n);
	if (n < 0)
		neg = -1;
	if (!(str = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	str[j] = '\0';
	j--;
	while (j > -1)
	{
		if (j == 0 && neg == -1)
			str[j] = '-';
		else
			str[j] = (n % 10) * neg + '0';
		n /= 10;
		j--;
	}
	return (str);
}
