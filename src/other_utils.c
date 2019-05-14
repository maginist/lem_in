/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 09:48:06 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/30 13:39:54 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		other_turn(int **matrix, t_room *tab, int *way, int room_n)
{
	int	i;
	int	lim;
	int	j;
	int	best;

	i = 0;
	j = 0;
	best = 0;
	//printf("si y a pas pouet c'est que ca plante du premier coup (room_n %d)\n", room_n);
	while (way[i] != room_n)//si ca segfault c'est peut etre la mais ca devrait pas
		i++;
	if (!(way[i] && i))
		return (0);
	i--;
	lim = matrix[way[i]][way[i]];
	while (lim > 0)
	{
		if (matrix[way[i]][j] == -1)
		{
			lim--;
			if (tab[j].taken == 0 && (best == 0 || tab[best].wth > tab[j].wth))
				best = j;
		}
		j++;
	}
	//	printf("pouet0\n");
	return ((best == 0 ? 0 : tab[best].wth));
}
