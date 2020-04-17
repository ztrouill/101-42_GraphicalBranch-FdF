/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/03 17:30:52 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 09:06:37 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				close_window(t_events *events)
{
	mlx_destroy_image(events->utilities->mlx_ptr, events->image.image_ptr);
	mlx_destroy_window(events->utilities->mlx_ptr,
	events->utilities->window_ptr);
	close(events->utilities->fd);
	FMOD_System_Close(events->audio.system);
	we_are_looking_for_freedom(&events->point);
	exit(EXIT_SUCCESS);
	return (0);
}

int				translate_points(int keycode, t_events *events)
{
	if (keycode == KEY_LEFT)
	{
		events->point.right = -1;
		events->point.up = 0;
		ft_translate(&events->point);
	}
	if (keycode == KEY_RIGHT)
	{
		events->point.right = 1;
		events->point.up = 0;
		ft_translate(&events->point);
	}
	if (keycode == KEY_UP)
	{
		events->point.up = 1;
		events->point.right = 0;
		ft_translate(&events->point);
	}
	if (keycode == KEY_DOWN)
	{
		events->point.up = -1;
		events->point.right = 0;
		ft_translate(&events->point);
	}
	return (0);
}

int				change_view(t_events *events)
{
	if (events->utilities->view_iso == 0 && events->utilities->view_para == 1)
	{
		events->utilities->view_iso = 1;
		place_iso_point(&events->point, *events->utilities);
		events->utilities->view_para = 0;
	}
	else
	{
		events->utilities->view_para = 1;
		place_para_point(&events->point, *events->utilities);
		events->utilities->view_iso = 0;
	}
	return (0);
}

int				zoom(int keycode, t_events *events)
{
	if (keycode == KEY_PLUS)
	{
		if (events->point.interval > events->utilities->height)
			return (-1);
		events->point.scale = 1;
		events->point.interval *= 2;
		place_point(&events->point, events->utilities);
		if (events->utilities->view_iso == 1)
			place_iso_point(&events->point, *events->utilities);
		else
			place_para_point(&events->point, *events->utilities);
	}
	if (keycode == KEY_MINUS)
	{
		if (events->point.interval == 1)
			return (-1);
		events->point.scale = -1;
		events->point.interval *= 0.9;
		place_point(&events->point, events->utilities);
		if (events->utilities->view_iso == 1)
			place_iso_point(&events->point, *events->utilities);
		else
			place_para_point(&events->point, *events->utilities);
	}
	return (0);
}
