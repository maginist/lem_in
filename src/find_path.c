/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/05/22 09:47:22 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	make_a_turn(int **matrix, t_room *tab, t_path *new, int node)
{
	int			i;

	i = 1;
	while (new->path[new->path_n - 2][i - 1] != node)
		i++;
	new->path[new->path_n - 2][i] = way_is_possible(matrix, tab, new,
			new->path_n - 2);
	tab[new->path[new->path_n - 2][i]].taken = new->path_n - 2 + 1;
}

void	try_path(int **matrix, t_room *tab, t_path *new, t_path *best)
{
	int			i;
	int			size;

	(void)matrix;
	size = calc_size(tab);
	i = check_nodes(0, 0, 0, 0) - 1;
	copy_best(best, new, size, tab);
	while (++i < size)
		if (tab[i].used == new->path_n - 2)
			tab[i].used = 0;
	tab[way_is_possible(matrix, tab, new, new->path_n - 1)].used = new->path_n;
	new->path[new->path_n - 2][new->len[new->path_n - 2] - 1] = 0;
}

int		for_j(t_path **new, int i)
{
	int			j;

	j = 0;
	while ((*new)->path[i][j] != 0)
		j++;
	return (j);
}

int		find_path(int **matrix, t_room *tab, t_path **new, t_path *best)
{
	int			i;
	int			j;
	int			node;

	i = (*new)->path_n - 2;
	while (++i < (*new)->path_n)
	{
		j = for_j(new, i);
		while (((*new)->path[i][j] = way_is_good(matrix, tab, *new, i)) > 1)
			j++;
		if ((*new)->path[i][j] == 0)
		{
			if ((i == (*new)->path_n - 1 || i == (*new)->path_n - 2)
					&& ((node = check_nodes(tab, new, best, matrix)) > 0))
				make_a_turn(matrix, tab, *new, node);
			else if (way_is_possible(matrix, tab, *new, (*new)->path_n - 1) > 0)
				try_path(matrix, tab, *new, best);
			else
				return (0);
			i = (*new)->path_n - 3;
		}
		else
			(*new)->len[i] = j + 1;
	}
	return (1);
}
