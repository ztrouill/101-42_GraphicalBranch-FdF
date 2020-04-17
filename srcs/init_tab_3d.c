/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_tab_3d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 20:45:47 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 21:06:28 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_tab_3d_last_dimension(t_point *point, int ***res)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i != point->line_len)
	{
		point->col_len = ft_strlen(point->tab[i]);
		point->col_len = ft_col_2d(point->col_len, point->tab[i]);
		while (j < point->col_len)
		{
			if (!(res[i][j] = (int*)malloc(sizeof(int) * 3)))
				return ;
			j++;
		}
		j = 0;
		i++;
	}
}

int				***init_tab_3d(t_point *point)
{
	int		i;
	int		j;
	int		***res;

	i = 0;
	j = 0;
	if (!(res = (int***)malloc(sizeof(int**) * point->line_len - 1)))
		return (NULL);
	while (i < point->line_len)
	{
		if (!(res[i] = (int**)malloc(sizeof(int*) * point->col_len - 1)))
			return (NULL);
		i++;
	}
	init_tab_3d_last_dimension(point, res);
	return (res);
}

int				ft_col_2d(int col_len, char *tab)
{
	int		i;
	int		end;

	end = col_len;
	i = 0;
	while (i <= end)
	{
		while (tab[i] == ' ' && tab[i] != '\0')
		{
			i++;
			col_len--;
		}
		if (tab[i] == ':')
			i++;
		if (i != end)
		{
			if (tab[i] != ' ' && tab[i + 1] != ' ')
				col_len--;
		}
		i++;
	}
	return (col_len + 1);
}
