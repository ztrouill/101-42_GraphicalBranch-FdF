/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 13:38:12 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 17:25:04 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double			percent(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int				get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static t_color			init_color(t_segment *segment, t_utilities *utilities,
						t_color *color)
{
	color->start_x = segment->start_x;
	color->start_y = segment->start_y;
	color->end_x = segment->x2;
	color->end_y = segment->y2;
	color->current_x = segment->x;
	color->current_y = segment->y;
	if (segment->c == 'h')
	{
		color->start_color = utilities->palette[0];
		color->end_color = utilities->palette[1];
		color->current_color = utilities->palette[0];
	}
	if (segment->c == 'v')
	{
		color->start_color = utilities->palette[1];
		color->end_color = utilities->palette[0];
		color->current_color = utilities->palette[1];
	}
	color->delta_x = segment->ex;
	color->delta_y = segment->ey;
	return (*color);
}

int						get_color(t_segment segment, t_utilities utilities)
{
	t_color			color;
	int				red;
	int				green;
	int				blue;
	double			percentage;

	color = init_color(&segment, &utilities, &color);
	if (color.current_color == color.end_color)
		return (color.current_color);
	if (color.delta_x > color.delta_y)
		percentage = percent(color.start_x, color.end_x, color.current_x);
	else
		percentage = percent(color.start_y, color.end_y, color.current_y);
	red = get_light((color.start_color >> 16) & 0xFF, (color.end_color >> 16)
			& 0xff, percentage);
	green = get_light((color.start_color >> 8) & 0xff, (color.end_color >> 8)
			& 0xff, percentage);
	blue = get_light(color.start_color & 0xff, color.end_color
			& 0xff, percentage);
	return ((red << 16) | (green << 8) | blue);
}
