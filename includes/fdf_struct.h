/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_struct.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 12:33:51 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 08:53:51 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include "../lib/FMOD/inc/fmod.h"

/*
 *** STRUCTURES ***
*/

typedef struct		s_point
{
	char			**tab;
	int				i;
	int				j;
	float			up;
	int				right;
	int				down;
	int				col_len;
	int				line_len;
	int				***matrice;
	int				***coord;
	int				coord_i;
	int				coord_j;
	int				ortho_x;
	int				ortho_y;
	int				ortho_z;
	int				interval;
	int				iso_x;
	int				iso_y;
	float			z;
	int				scale;
	int				tmp;
}					t_point;

typedef struct		s_segment
{
	int						x;
	int						y;
	int						x2;
	int						y2;
	char					c;
	int						dx;
	int						dy;
	int						ex;
	int						ey;
	int						x_inc;
	int						y_inc;
	int						sx;
	int						sy;
	int						i;
	int						j;
	int						color;
	int						start_x;
	int						start_y;
}					t_segment;

typedef struct		s_utilities
{
	void					*window_ptr;
	int						width;
	int						height;
	void					*mlx_ptr;
	int						tool_bar;
	int						view_iso;
	int						view_para;
	int						palette[2];
	int						color;
	int						play;
	int						double_seg;
	int						fd;
	int						error;
	int						refresh;
}					t_utilities;

typedef struct		s_image
{
	void					*image_ptr;
	int						*image_str;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
}					t_image;

typedef struct		s_audio
{
	FMOD_SYSTEM				*system;
	FMOD_SOUND				*sound;
	FMOD_CHANNELGROUP		*channel_group;
	FMOD_CHANNEL			*channel;
	FMOD_DSP				*dsp;
	FMOD_BOOL				*bol;
}					t_audio;

typedef struct		s_events
{
	t_utilities				*utilities;
	t_point					point;
	t_image					image;
	t_audio					audio;
	t_segment				*segment;
}					t_events;

typedef struct		s_color
{
	int						start_x;
	int						start_y;
	int						end_x;
	int						end_y;
	int						current_x;
	int						current_y;
	int						delta_x;
	int						delta_y;
	int						start_color;
	int						end_color;
	int						current_color;
}					t_color;

#endif
