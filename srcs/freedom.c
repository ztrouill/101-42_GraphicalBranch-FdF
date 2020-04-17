/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   freedom.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 18:32:12 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 09:04:16 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			free_tab_int(int ***tab, t_point *point)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab)
	{
		while (i < point->line_len)
		{
			point->col_len = count_col(point);
			while (j < point->col_len)
			{
				free(tab[i][j]);
				tab[i][j] = NULL;
				j++;
			}
			j = 0;
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		tab = NULL;
	}
}

void				we_are_looking_for_freedom(t_point *point)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	free_tab_int(point->coord, point);
	free_tab_int(point->matrice, point);
	while (point->tab)
	{
		while (point->tab[i])
		{
			free(point->tab[i]);
			point->tab[i] = NULL;
			i++;
		}
		free(point->tab);
		point->tab = NULL;
	}
}
