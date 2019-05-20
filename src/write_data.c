/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:34 by maginist          #+#    #+#             */
/*   Updated: 2019/05/20 11:42:39 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	write_path(t_path *best, t_room *tab, int j, int *first)
{
	int	i;

	i = best->len[j] - 1;
	while (i >= 0)
	{
		if (tab[best->path[j][i]].taken > 0 && *first == 1)
		{
			ft_printf("L%d-%s"
					, tab[best->path[j][i]].taken, tab[best->path[j][i]].name);
			*first = 0;
		}
		else if (tab[best->path[j][i]].taken > 0)
			ft_printf(" L%d-%s"
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
