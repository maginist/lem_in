/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:24:49 by floblanc          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/04/24 10:38:49 by maginist         ###   ########.fr       */
=======
/*   Updated: 2019/04/19 17:16:53 by floblanc         ###   ########.fr       */
>>>>>>> ef60ff89d9f113862f402f12f3ad8a3e84df2cda
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		onelink_startend(t_room *tab, t_path **best, int **matrix)
{
	if (matrix[0][1] == -1)
	{
		//on bloque les autres chemins puis boom tout dans le best;
	}
	else
		return (0);
}

void	put_wth(int **matrix, int i, int j, t_room *tab)
{
	static int	size;

	if (!(size))
		size = calc_size(tab);
	if (i >= size || j >= size || i == 0)
		return ;
	while (j < size && (j == 1 || matrix[i][j] != -1 || (tab[j].wth != 0
					&& tab[j].wth <= tab[i].wth + 1)))
		j++;
	if (j == size)
		return ;
	tab[j].wth = tab[i].wth + 1;
	put_wth(matrix, i, j + 1, tab);
	put_wth(matrix, j, 0, tab);
}

void	onelink_startend(int ant_n)
{
	int i;

	i = 1;
	printf("\n");
	while (i != ant_n)
	{
		printf("L%d-end ", i);
		i++;
	}
	printf("L%d-end", i);
}

int		fill_matrix(t_room *tab, int **matrix, char *str, int size)
{
	int		i;
	int		run;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	str[i] = '\0';
	run = 0;
	while (run < size && ft_strcmp(tab[run].name, str) != 0)
		run++;
	str[i] = '-';
	if (run < size && fill_matrix2(tab, str + i + 1, matrix, run))
		return (1);
	return (0);
}
