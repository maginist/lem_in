/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:53:13 by maginist          #+#    #+#             */
/*   Updated: 2018/11/14 15:22:55 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpymin(char *str, char *p, int mi, int mx)
{
	int i;

	i = 0;
	while (mi <= mx)
	{
		str[i] = p[mi];
		i++;
		mi++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		mx;
	int		mi;
	char	*str;
	char	*p;

	mi = 0;
	if (s)
	{
		p = (char*)s;
		mx = ft_strlen(p) - 1;
		while (p[mx] == ' ' || p[mx] == ',' || p[mx] == '\n' || p[mx] == '\t')
			mx--;
		while (p[mi] == ' ' || p[mi] == ',' || p[mi] == '\n' || p[mi] == '\t')
			mi++;
		if (mi > mx + 1)
			return (ft_strnew(0));
		if (!(str = (char*)malloc(sizeof(char) * (mx - mi) + 2)))
			return (NULL);
		return (ft_cpymin(str, p, mi, mx));
	}
	return (NULL);
}
