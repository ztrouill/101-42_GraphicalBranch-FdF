/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 16:15:42 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 09:03:58 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				draw_lines(t_point *point, t_utilities *utilities,
					t_image image, t_segment segment)
{
	while (point->coord_i != point->line_len)
	{
		point->col_len = count_col(point);
		while (point->coord_j < point->col_len)
		{
			if (point->coord_i != point->line_len - 1)
			{
				segment.c = 'v';
				ft_bresenham(utilities, point, image, segment);
			}
			if (point->coord_j != point->col_len - 1)
			{
				segment.c = 'h';
				ft_bresenham(utilities, point, image, segment);
			}
			point->coord_j++;
		}
		point->coord_j = 0;
		point->coord_i++;
	}
	point->coord_i = 0;
}

void				draw_double_lines(t_point *point, t_utilities *utilities,
					t_image image)
{
	t_segment		segment;

	while (point->coord_i != point->line_len)
	{
		point->col_len = ft_strlen(point->tab[point->coord_i]);
		point->col_len = ft_col_2d(point->col_len,
		point->tab[point->coord_i]);
		while (point->coord_j != point->col_len)
		{
			if (point->coord_j != point->col_len - 1)
			{
				segment.c = 'h';
				ft_bresenham(utilities, point, image, segment);
			}
			if (point->coord_j == point->col_len - 1)
				break ;
			point->coord_j += 3;
		}
		point->coord_j = 0;
		point->coord_i++;
	}
	point->coord_i = 0;
}
