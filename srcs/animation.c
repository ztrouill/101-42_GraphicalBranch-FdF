/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   animation.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 12:20:34 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 09:11:38 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		up_z_axis(t_events *events)
{
	float t;

	t = 0;
	usleep(52000);
	if (events->utilities->play == 1)
		return (-1);
	FMOD_DSP_GetParameterFloat(events->audio.dsp,
			FMOD_DSP_FFT_DOMINANT_FREQ, &t, 0, 0);
	if (t < 1000)
		events->utilities->palette[0] += t;
	else if (t > 3000)
		events->utilities->palette[1] += t;
	t = t / 1000;
	events->point.up = t;
	if (events->utilities->view_iso == 1)
		place_iso_point(&events->point, *events->utilities);
	if (events->utilities->view_para == 1)
		place_para_point(&events->point, *events->utilities);
	refresh_window(events);
	return (0);
}
