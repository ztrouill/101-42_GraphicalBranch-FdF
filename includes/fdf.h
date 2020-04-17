/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 11:31:57 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 09:07:24 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "../lib/minilibx_macos/mlx.h"
# include "fdf_struct.h"
# include "fdf_define.h"

/*
 *** FONCTIONS PARSING ***
*/

char				**create_tab_2d(const int fd, char **tab);
int					check_tab(char **tab);
int					ft_col_2d(int col_len, char *tab);
int					count_col(t_point *point);
/*
 *** FONCTIONS CHECK ERROR ***
*/

int					check_fd(int fd);
int					check_name_file(char *argv, int argv_num);
void				display_error_and_exit(int error);
void				check_size_col(t_point *point, t_utilities utilities);

/*
 *** FONCTIONS INITIALISATION STRUCTURES // TABLEAUX ***
*/

void				init_segment(t_point *point, t_segment *segment,
					t_utilities *utilities);
void				init_segment_h(t_point *point, t_segment *segment,
					t_utilities *utilities);
void				init_segment_v(t_point *point, t_segment *segment,
					t_utilities *utilities);
void				init_segment_h_2(t_point *point, t_segment *segment,
					t_utilities *utilities);
void				init_audio(t_utilities *utilities, t_audio *audio,
					char *argv);
void				init_all_struct(t_utilities *utilities, t_events *events,
					char *argv);
void				init_palette(t_utilities *utilities);
int					***init_tab_3d(t_point *point);

/*
 *** FONCTIONS PLACEMENT POINTS ***
*/

void				place_point(t_point *point, t_utilities *utilities);
void				place_iso_point(t_point *point, t_utilities utilities);
void				place_para_point(t_point *point, t_utilities utilities);

/*
 *** FONCTIONS TRACE DE SEGMENTS ***
*/

void				draw_lines(t_point *point, t_utilities *utilities,
					t_image image, t_segment segment);
void				draw_double_lines(t_point *point, t_utilities *utilities,
					t_image image);
void				ft_bresenham(t_utilities *utilities, t_point *point,
					t_image image, t_segment segment);
void				ft_bresenham_2(t_utilities *utilities, t_point *point,
					t_image image, t_segment segment);

/*
 *** FONCTIONS TRANSFORMATIONS ***
*/

int					ft_homothetie(t_point *point, t_utilities utilities);
int					ft_center_points(t_point *point, t_utilities utilities);
int					ft_translate(t_point *point);

/*
 *** FONCTIONS EVENEMENTS ***
*/

int					translate_points(int keycode, t_events *events);
int					manage_events(int keycode, t_events *events);
int					close_window(t_events *events);
int					change_view(t_events *events);
int					zoom(int keycode, t_events *events);
int					change_color(t_events *events);
int					up_z_axis(t_events *events);
int					play_song(t_events *events);

/*
 *** FONCTIONS DISPLAY MAP ***
*/

void				display_tool_bar(t_utilities *utilities);
int					get_color(t_segment segment, t_utilities utilities);
void				refresh_window(t_events *events);
int					check_end_str(t_segment *segment, t_utilities *utilities,
					t_point *point);
void				display_window(t_utilities utilities, t_point *point,
					t_image *image, t_segment segment);

/*
 *** FONCTIONS FREE ***
*/
void				we_are_looking_for_freedom(t_point *point);
#endif
