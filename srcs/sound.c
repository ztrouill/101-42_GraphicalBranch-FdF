/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sound.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 09:36:22 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 16:52:50 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			init_audio(t_utilities *utilities, t_audio *audio, char *argv)
{
	audio->dsp = NULL;
	audio->bol = &utilities->play;
	FMOD_System_Create(&audio->system);
	FMOD_System_Init(audio->system, 1, FMOD_INIT_NORMAL, NULL);
	FMOD_System_CreateStream(audio->system, argv,
							FMOD_LOOP_NORMAL, 0, &audio->sound);
	if (!audio->sound)
		return ;
	FMOD_System_GetMasterChannelGroup(audio->system, &audio->channel_group);
	FMOD_System_GetChannel(audio->system, 0, &audio->channel);
	FMOD_ChannelGroup_GetDSP(audio->channel_group, -1, &audio->dsp);
	FMOD_System_CreateDSPByType(audio->system, FMOD_DSP_TYPE_FFT, &audio->dsp);
	FMOD_ChannelGroup_AddDSP(audio->channel_group, -1, audio->dsp);
	FMOD_Channel_AddDSP(audio->channel, FMOD_DSP_PARAMETER_DATA_TYPE_FFT,
						audio->dsp);
	FMOD_DSP_SetActive(audio->dsp, 1);
}

int				play_song(t_events *events)
{
	if (!events->audio.sound)
		return (-1);
	FMOD_System_PlaySound(events->audio.system, events->audio.sound,
	events->audio.channel_group, *events->audio.bol, &events->audio.channel);
	if (events->utilities->play == 1)
		refresh_window(events);
	if (events->utilities->play == 0)
		mlx_loop_hook(events->utilities->mlx_ptr, up_z_axis, events);
	return (0);
}
