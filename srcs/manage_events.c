/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_events.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/20 18:38:58 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 13:08:26 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			refresh_window(t_events *events)
{
	mlx_clear_window(events->utilities->mlx_ptr, events->utilities->window_ptr);
	mlx_destroy_image(events->utilities->mlx_ptr, events->image.image_ptr);
	events->image.image_ptr = mlx_new_image(events->utilities->mlx_ptr,
	events->utilities->width, events->utilities->height);
	events->image.image_str = (int*)mlx_get_data_addr(events->image.image_ptr,
	&events->image.bits_per_pixel, &events->image.size_line,
	&events->image.endian);
	events->utilities->refresh = 1;
	display_window(*events->utilities, &events->point, &events->image,
					*events->segment);
}

static void		lets_dance(t_events *events)
{
	if (events->utilities->play == 1)
		events->utilities->play = 0;
	else if (events->utilities->play == 0)
		events->utilities->play = 1;
	events->audio.bol = &events->utilities->play;
	play_song(events);
}

int				manage_events(int keycode, t_events *events)
{
	if (keycode == KEY_ESC)
		close_window(events);
	if ((keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT ||
		keycode == KEY_RIGHT) && events->utilities->play != 0)
		translate_points(keycode, events);
	if (keycode == KEY_V)
		change_view(events);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		zoom(keycode, events);
	if (keycode == KEY_H)
	{
		if (events->utilities->tool_bar == 1)
			events->utilities->tool_bar = 0;
		else
			events->utilities->tool_bar = 1;
	}
	if (keycode == KEY_SPACE)
		lets_dance(events);
	if (keycode != KEY_SPACE && keycode != KEY_ESC)
		refresh_window(events);
	return (0);
}
