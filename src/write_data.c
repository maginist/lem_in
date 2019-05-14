/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:34 by maginist          #+#    #+#             */
/*   Updated: 2019/05/14 12:12:56 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	write_path(t_path *best, t_room *tab, int j, int ant_n)
{
	int	i;

	i = best->len[j] - 1;
	ant_n = 0;
	while (i >= 0)
	{
		if (tab[best->path[j][i]].taken > 0
				&& (i == 0 || tab[best->path[j][i - 1]].taken <= 0)
				&& (j == best->path_n - 1
					|| (j < best->path_n - 1 
						&& best->path[j + 1][best->len[j + 1]]
						+ best->len[j + 1] <= 1)))
			ft_printf("L%d-%s"
					, tab[best->path[j][i]].taken, tab[best->path[j][i]].name);
		else if (tab[best->path[j][i]].taken > 0)
			ft_printf("L%d-%s "
					, tab[best->path[j][i]].taken, tab[best->path[j][i]].name);
		i--;
	}
}

void	write_data(t_write **begin)
{
	t_write	*current;

	if (!(begin && *begin))
		return ;
	current = *begin;
	while (current)
	{
		ft_putendl(current->str);
		current = current->next;
	}
	free_lst_write(begin);
}
