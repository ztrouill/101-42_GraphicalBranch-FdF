/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_point.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 09:30:54 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 10:13:38 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			find_z(t_point *point)
{
	char		*z_tmp;
	int			i;

	i = 0;
	z_tmp = ft_strnew(4);
	while (point->tab[point->i][point->j] != ' ' &&
			point->tab[point->i][point->j] != '\0')
	{
		if (point->tab[point->i][point->j] == ' ' ||
			point->tab[point->i][point->j] == ':')
			break ;
		z_tmp[i] = point->tab[point->i][point->j];
		i++;
		point->j++;
	}
	point->j -= 1;
	i = 0;
	point->z = ft_atoi(z_tmp);
	if ((point->col_len > 25 || point->col_len < 15) && point->z < 10)
		point->ortho_z -= point->interval * point->z;
	else
		point->ortho_z -= point->interval * point->z / 4;
	if (point->tmp == 3)
		point->ortho_z = -point->ortho_z;
	ft_strdel(&z_tmp);
}

static void			fill_matrice_and_incr_position(t_point *point,
			t_utilities utilities)
{
	if (point->tmp == 1)
	{
		point->matrice[point->coord_i][point->coord_j][0] = point->ortho_x;
		point->matrice[point->coord_i][point->coord_j][1] = point->ortho_y;
		point->matrice[point->coord_i][point->coord_j][2] = point->ortho_z;
		point->ortho_z = 0;
		point->ortho_x += point->interval;
	}
	if (point->tmp == 2)
	{
		point->ortho_y += point->interval * 2;
		point->ortho_z = 0;
		point->ortho_x = utilities.width / 4;
	}
}

static void			check_special_char(t_point *point)
{
	if (point->tab[point->i][point->j] == ' ')
	{
		point->ortho_x += point->interval;
		if (point->tab[point->i][point->j + 1] == ' ')
			point->j++;
		point->j++;
	}
	if (point->tab[point->i][point->j] == ':')
	{
		point->ortho_x -= point->interval;
		point->j++;
	}
	if (point->tab[point->i][point->j] != ' ' &&
		point->tab[point->i][point->j] != ':')
		find_z(point);
}

void				place_point(t_point *point, t_utilities *utilities)
{
	int		i;

	i = 0;
	while (point->tab[point->i])
	{
		point->col_len = count_col(point);
		while (point->coord_j < point->col_len)
		{
			if (utilities->double_seg == 3)
				point->tmp = 3;
			check_special_char(point);
			point->tmp = 1;
			fill_matrice_and_incr_position(point, *utilities);
			point->coord_j++;
			point->j++;
		}
		point->tmp = 2;
		fill_matrice_and_incr_position(point, *utilities);
		point->j = 0;
		point->coord_j = 0;
		point->coord_i++;
		point->i++;
	}
	point->i = 0;
	point->coord_i = 0;
}
