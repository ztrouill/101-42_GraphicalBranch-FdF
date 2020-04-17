/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_segment.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 12:48:32 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 09:00:49 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			init_segment_h(t_point *point, t_segment *segment,
					t_utilities *utilities)
{
	segment->x2 = point->coord[point->coord_i][point->coord_j + 1][0];
	segment->y2 = point->coord[point->coord_i][point->coord_j + 1][1];
	if (segment->x > segment->x2)
		segment->x_inc = -1;
	if (segment->y > segment->y2)
		segment->y_inc = -1;
	if (point->coord_j + 1 != point->col_len)
	{
		if (point->coord[point->coord_i][point->coord_j][2] != 0 &&
			point->coord[point->coord_i][point->coord_j + 1][2] != 0)
			segment->color = utilities->palette[1];
		else
			segment->color = utilities->palette[0];
	}
}

void			init_segment_v(t_point *point, t_segment *segment,
					t_utilities *utilities)
{
	segment->x2 = point->coord[point->coord_i + 1][point->coord_j][0];
	segment->y2 = point->coord[point->coord_i + 1][point->coord_j][1];
	if (segment->x > segment->x2)
		segment->x_inc = -1;
	if (segment->y > segment->y2)
		segment->y_inc = -1;
	if (point->coord_i + 1 != point->line_len)
	{
		if (point->coord[point->coord_i][point->coord_j][2] != 0 &&
			point->coord[point->coord_i + 1][point->coord_j][2] != 0)
			segment->color = utilities->palette[1];
		else
			segment->color = utilities->palette[0];
	}
}

void			init_segment(t_point *point, t_segment *segment,
					t_utilities *utilities)
{
	segment->x = point->coord[point->coord_i][point->coord_j][0];
	segment->y = point->coord[point->coord_i][point->coord_j][1];
	segment->x_inc = 1;
	segment->y_inc = 1;
	if (utilities->double_seg == 1)
		init_segment_h_2(point, segment, utilities);
	if (segment->c == 'h' && utilities->double_seg != 1)
		init_segment_h(point, segment, utilities);
	if (segment->c == 'v')
		init_segment_v(point, segment, utilities);
	segment->ex = abs(segment->x2 - segment->x);
	segment->ey = abs(segment->y2 - segment->y);
	segment->dx = segment->ex * 2;
	segment->dy = segment->ey * 2;
	segment->sx = segment->ex;
	segment->sy = segment->ey;
	segment->start_x = segment->x;
	segment->start_y = segment->y;
	segment->i = 0;
}

void			init_segment_h_2(t_point *point, t_segment *segment,
					t_utilities *utilities)
{
	segment->x2 = point->coord[point->coord_i][point->coord_j + 3][0];
	segment->y2 = point->coord[point->coord_i][point->coord_j + 3][1];
	if (segment->x > segment->x2)
		segment->x_inc = -1;
	if (segment->y > segment->y2)
		segment->y_inc = -1;
	if (point->coord_j + 1 != point->col_len)
	{
		if (point->coord[point->coord_i][point->coord_j][2] != 0 &&
			point->coord[point->coord_i][point->coord_j + 3][2] != 0)
			segment->color = utilities->palette[1];
		else
			segment->color = utilities->palette[0];
	}
}
