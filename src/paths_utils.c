/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:58:32 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/14 12:42:35 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ant_walk(t_path *best, t_room *tab, int j)
{
	int i;

	i = best->len[j] - 1;
	while (i > 0)
	{
		tab[best->path[j][i]].taken = tab[best->path[j][i - 1]].taken;
		i--;
	}
}

void	use_path(t_path *best, t_room *tab, int size)
{
	int	i;
	int	j;
	int	ant_n;

	i = 1;
	j = 1;
	if (!(best))// c'est pas sense arriver
		return ;
	ant_n = tab[0].taken;
	while (j < size)
		tab[j++].taken = 0;
	while ((best->step)-- > 0)
	{
		j = -1;
		write(1, "\n", 1);
		while (++j < best->path_n && best->len[j] > 0)
		{
			ant_walk(best, tab, j);
			if (best->path[j][best->len[j]] > 0 /*&& tab[0].taken > 0*/)
			{
				tab[best->path[j][0]].taken = i++;
				(tab[0].taken)--;
			}
			else
				tab[best->path[j][0]].taken = 0;
			(best->path[j][best->len[j]]) -= 1;
			write_path(best, tab, j, ant_n);
		}
	}
}

int		calc_step(t_path *struc, int ant_n, int path_n)
{
	int	i;

	//printf("les fourmis %d\n", ant_n);
//	printf("struc->len[%d] = %d\n", path_n - 1, struc->len[0]);
//	printf("CALCUL path_n = %d et strucpath_n = %d\n", path_n, struc->path_n);
	struc->path[0][struc->len[0]] = ant_n;
	if (path_n == 1 || struc->len[1] <= 0)
	{
		struc->step = struc->len[0] + struc->path[0][struc->len[0]] - 1;
		return (struc->step);
	}
	i = 1;
	//printf("CALCUL222\n");
	while (i > 0)
	{
		i = 0;
		while ((i < path_n - 1) && struc->len[i + 1] > 0
				&& struc->len[i + 1] > 0 && (struc->len[i]
					+ struc->path[i][struc->len[i]] - 1 >= struc->len[i + 1]
					+ struc->path[i + 1][struc->len[i + 1]]))
			i++;
		if (i > 0)
			struc->path[0][struc->len[0]]--;
		if (i > 0)
			struc->path[i][struc->len[i]]++;
	//	printf("struc->path[%d][%d] = %d\n", 0, struc->len[0],struc->path[0][struc->len[0]]);
	//	printf("struc->path[%d][%d] = %d\n", i, struc->len[i],struc->path[i][struc->len[i]]);
	}
	//printf("add is %d + %d\n",struc->len[1], struc->path[1][struc->len[1]] - 1);
	struc->step = struc->len[1] + (struc->path[1][struc->len[1]] - 1);
	i = -1;
//	while (struc->len[++i] > 0)
	//	printf("path[%d](len = %d) got %d ants\n", i, struc->len[i], struc->path[i][struc->len[i]]);
	return (struc->step);
}
