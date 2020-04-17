/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:27:05 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 12:38:07 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			ft_bresenham_horiz(t_utilities *utilities, t_point *point,
					t_image image, t_segment segment)
{
	segment.c = 'v';
	while (segment.i++ <= segment.sy)
	{
		segment.j = segment.y * utilities->width + segment.x;
		if (check_end_str(&segment, utilities, point) == -1)
			break ;
		if (point->coord_j + 1 != point->col_len)
		{
			if (point->coord[point->coord_i][point->coord_j][2] != 0 &&
				point->coord[point->coord_i][point->coord_j + 1][2] == 0)
				segment.color = get_color(segment, *utilities);
		}
		image.image_str[segment.j++] = segment.color;
		segment.y += segment.y_inc;
		segment.ey -= segment.dx;
		if (segment.ey < 0)
		{
			segment.x += segment.x_inc;
			segment.ey += segment.dy;
		}
	}
}

static void			ft_bresenham_horiz_2(t_utilities *utilities, t_point *point,
					t_image image, t_segment segment)
{
	while (segment.i++ <= segment.sx)
	{
		segment.j = segment.y * utilities->width + segment.x;
		if (check_end_str(&segment, utilities, point) == -1)
			break ;
		if (point->coord_j + 1 != point->col_len)
		{
			if (point->coord[point->coord_i][point->coord_j][2] == 0 &&
				point->coord[point->coord_i][point->coord_j + 1][2] != 0)
				segment.color = get_color(segment, *utilities);
			if (segment.c == 'v')
				segment.color = get_color(segment, *utilities);
		}
		image.image_str[segment.j++] = segment.color;
		segment.x += segment.x_inc;
		segment.ex -= segment.dy;
		if (segment.ex < 0)
		{
			segment.y += segment.y_inc;
			segment.ex += segment.dx;
		}
	}
}

void				ft_bresenham_2(t_utilities *utilities, t_point *point,
					t_image image, t_segment segment)
{
	init_segment(point, &segment, utilities);
	if (segment.c == 'h')
	{
		if (segment.sx < segment.sy)
			ft_bresenham_horiz(utilities, point, image, segment);
		if (segment.sy < segment.sx)
		{
			if (utilities->view_para == 1 &&
				point->coord[point->coord_i][point->coord_j][2] != 0 &&
				point->coord[point->coord_i][point->coord_j + 1][2] == 0)
				segment.c = 'v';
			ft_bresenham_horiz_2(utilities, point, image, segment);
		}
	}
}
