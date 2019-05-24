/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:52:42 by maginist          #+#    #+#             */
/*   Updated: 2019/05/24 13:20:10 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		way_is_possible2(t_room *tab, int i, int way, int *best)
{
	if (i != 0 && (i == 1 ||
			(tab[i].taken == 0 && tab[i].used != way + 1
			&& ((*best) == 0 || tab[(*best)].wth > tab[i].wth)
			&& tab[i].wth > 0)))
		(*best) = i;
	if ((*best) == 1)
		return (0);
	else
		return (1);
}

int		way_is_good(int **matrix, t_room *tab, t_path *new, int way)
{
	int	pos;
	int	lim;
	int	best;
	int	i;

	pos = 0;
	while (new->path[way][pos + 1] != 0 && new->path[way][pos + 1])
		pos++;
	lim = matrix[new->path[way][pos]][new->path[way][pos]];
	best = 0;
	i = -1;
	while (lim > 0)
	{
		if (matrix[new->path[way][pos]][++i] == -1 && lim-- > 0)
			if (way_is_possible2(tab, i, way, &best) == 0)
				break ;
	}
	if (best > 0)
	{
		pos = (new->path[way][pos] == 0 ? 0 : pos);
		if (matrix[best][best] > 2 && best != 1)
			new->node[way][++pos] = best;
		tab[best].taken = way + 1;
	}
	return (best);
}

int		way_is_possible(int **matrix, t_room *tab, t_path *new, int way)
{
	int	pos;
	int	lim;
	int	best;
	int	i;

	pos = 0;
	while (new->path[way][pos + 1] != 0 && new->path[way][pos + 1])
		pos++;
	lim = matrix[new->path[way][pos]][new->path[way][pos]];
	best = 0;
	i = -1;
	while (lim > 0)
	{
		if (matrix[new->path[way][pos]][++i] == -1 && lim-- > 0)
			if (i != 0 && (i == 1 ||
						(tab[i].taken == 0 && tab[i].used != way + 1
						&& (!(best) || tab[best].wth > tab[i].wth)
						&& tab[i].wth > 0)))
				best = i;
		if (best == 1)
			break ;
	}
	return (best);
}

int		close_path(t_path *new, t_room *tab, int size, int f_case)
{
	int	i;

	i = 0;
	if (f_case > 0)
		tab[f_case].used = new->path_n;
	while (new->path[new->path_n - 1][i] != 0)
	{
		if (i == 0)
			tab[new->path[new->path_n - 1][i]].used = new->path_n;
		tab[new->path[new->path_n - 1][i]].taken = 0;
		new->path[new->path_n - 1][i++] = 0;
	}
	i = 0;
	while (i < size)
	{
		if (tab[i].used != 0 && tab[i].used != new->path_n)
			tab[i].used = 0;
		i++;
	}
	return (0);
}
