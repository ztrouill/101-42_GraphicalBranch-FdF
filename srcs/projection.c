/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_point_view.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 16:29:16 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 10:13:53 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		coordinate_transformation(t_point *point, int view)
{
	if (view == 1)
	{
		point->coord[point->coord_i][point->coord_j][2] = point->z;
		point->coord[point->coord_i][point->coord_j][0] =
		(point->iso_x - point->iso_y) * cos(0.523599);
		point->coord[point->coord_i][point->coord_j][1] = (point->z +
		(point->iso_x + point->iso_y) * sin(0.523599));
	}
	if (view == 2)
	{
		point->coord[point->coord_i][point->coord_j][2] = point->z;
		point->coord[point->coord_i][point->coord_j][0] = point->iso_x + 1
		* cos(0.525321) * -point->iso_y;
		point->coord[point->coord_i][point->coord_j][1] = point->z + 1 *
		sin(0.8509035) * point->iso_y;
	}
}

void			place_iso_point(t_point *point, t_utilities utilities)
{
	int		view;

	view = 1;
	while (point->coord_i != point->line_len)
	{
		point->col_len = count_col(point);
		while (point->coord_j < point->col_len)
		{
			point->iso_x = point->matrice[point->coord_i][point->coord_j][0] *
			0.82;
			point->iso_y = point->matrice[point->coord_i][point->coord_j][1] *
			0.82;
			point->z = point->matrice[point->coord_i][point->coord_j][2] *
			0.82;
			if (point->up != 0 && utilities.play == 0)
				point->z = (point->z / 2) * point->up;
			coordinate_transformation(point, view);
			point->coord_j++;
		}
		point->coord_j = 0;
		point->coord_i++;
	}
	point->coord_i = 0;
	ft_center_points(point, utilities);
}

void			place_para_point(t_point *point, t_utilities utilities)
{
	int		view;

	view = 2;
	while (point->coord_i != point->line_len)
	{
		point->col_len = count_col(point);
		while (point->coord_j < point->col_len)
		{
			point->iso_x = point->matrice[point->coord_i][point->coord_j][0];
			point->iso_y = point->matrice[point->coord_i][point->coord_j][1] *
			0.7;
			point->z = point->matrice[point->coord_i][point->coord_j][2];
			if (point->up != 1 && utilities.play == 0)
				point->z = (point->z / 2) * point->up;
			coordinate_transformation(point, view);
			point->coord_j++;
		}
		point->coord_j = 0;
		point->coord_i++;
	}
	point->coord_i = 0;
	ft_center_points(point, utilities);
}
