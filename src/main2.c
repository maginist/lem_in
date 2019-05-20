/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:29:44 by maginist          #+#    #+#             */
/*   Updated: 2019/05/20 17:54:37 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main_findpath(int **matrix, t_room *tab, t_path *new, t_path *best)
{
	static int	size;

	if (!size)
		size = calc_size(tab);
	tab[new->path[0][0]].taken = 1;
	copy_best(best, new, size, tab);
	if (!(find_path(matrix, tab, &new, best)))
		return (0);
	else
	{
		sort_paths(&new, size, tab, matrix);
		return (1);
	}
}

void	main3_ter(int **matrix, t_room *tab, t_path **new, int i)
{
	static int	size;

	if (!(size))
		size = calc_size(tab);
	clean_wth(tab, size);
	put_wth(matrix, tab, size);
	init_t_path(new, size, i);
	return ;
}

int		main2_onelink(int **matrix, t_room *tab, int ant_n, t_write **str)
{
	int	size;

	size = calc_size(tab);
	if (matrix[0][1] == -1)
	{
		write_data(str);
		onelink_startend(ant_n);
		free_lst_write(str);
		free_room_tab(&tab, size);
		free_matrix(&matrix, size);
		return (0);
	}
	return (1);
}
