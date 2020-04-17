/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 16:22:26 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 09:06:04 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_translate(t_point *point)
{
	int		move_px;

	move_px = 50;
	while (point->coord_i != point->line_len)
	{
		point->col_len = count_col(point);
		while (point->coord_j < point->col_len)
		{
			if (point->right == 1)
				point->coord[point->coord_i][point->coord_j][0] += move_px;
			else if (point->right == -1)
				point->coord[point->coord_i][point->coord_j][0] -= move_px;
			else if (point->up == 1)
				point->coord[point->coord_i][point->coord_j][1] -= move_px;
			else if (point->up == -1)
				point->coord[point->coord_i][point->coord_j][1] += move_px;
			point->coord_j++;
		}
		point->coord_j = 0;
		point->coord_i++;
	}
	point->coord_i = 0;
	return (0);
}

int			ft_center_points(t_point *point, t_utilities utilities)
{
	int		a;
	int		b;

	a = utilities.width / 2 -
	point->coord[point->line_len / 2][point->col_len / 2][0];
	b = utilities.height / 2 -
	point->coord[point->line_len / 2][point->col_len / 2][1];
	while (point->coord_i != point->line_len)
	{
		point->col_len = count_col(point);
		while (point->coord_j < point->col_len)
		{
			point->coord[point->coord_i][point->coord_j][0] += a;
			point->coord[point->coord_i][point->coord_j][1] += b;
			point->coord_j++;
		}
		point->coord_j = 0;
		point->coord_i++;
	}
	point->coord_i = 0;
	return (0);
}

int			ft_homothetie(t_point *point, t_utilities utilities)
{
	float	k;

	if (point->scale == 1)
		k = 1.5;
	if (point->scale == -1)
		k = 0.5;
	point->coord_i = 0;
	while (point->coord_i != point->line_len)
	{
		point->col_len = count_col(point);
		while (point->coord_j <= point->col_len)
		{
			point->coord[point->coord_i][point->coord_j][0] =
			point->coord[point->coord_i][point->coord_j][0] * k;
			point->coord[point->coord_i][point->coord_j][1] =
			point->coord[point->coord_i][point->coord_j][1] * k;
			point->coord_j++;
		}
		point->coord_j = 0;
		point->coord_i++;
	}
	point->coord_i = 0;
	ft_center_points(point, utilities);
	return (0);
}
