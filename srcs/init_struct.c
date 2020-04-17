/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_struct.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 09:43:50 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 09:48:34 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			init_utilities(t_utilities *utilities)
{
	utilities->mlx_ptr = mlx_init();
	utilities->height = HEIGHT;
	utilities->width = WIDTH;
	utilities->tool_bar = 1;
	utilities->view_iso = 1;
	utilities->view_para = 0;
	utilities->play = 1;
	utilities->color = 0;
	utilities->palette[0] = PINK;
	utilities->palette[1] = CYAN;
	utilities->refresh = 0;
	if (utilities->double_seg != 2 && utilities->double_seg != 3)
		utilities->double_seg = 0;
}

static void			init_point(const int fd, t_utilities utilities,
					t_point *point)
{
	point->i = 0;
	point->j = 0;
	point->tab = create_tab_2d(fd, point->tab);
	point->line_len = ft_line_nb(point->tab);
	point->col_len = ft_strlen(point->tab[point->i]);
	point->interval = (ceil(utilities.width / 2 / point->col_len));
	point->col_len = ft_col_2d(point->col_len, point->tab[point->i]);
	if (utilities.double_seg == 2)
		point->tmp = 1;
	point->ortho_x = utilities.width / 4;
	point->ortho_y = utilities.height / 2;
	point->ortho_z = 0;
	point->iso_x = point->ortho_x - point->ortho_y;
	point->iso_y = (point->ortho_x + point->ortho_y) / 2;
	point->coord_i = 0;
	point->coord_j = 0;
	point->coord = init_tab_3d(point);
	point->matrice = init_tab_3d(point);
	point->coord[point->coord_i][point->coord_j][0] = 0;
	point->coord[point->coord_i][point->coord_j][1] = 0;
	point->up = 1;
	point->right = 0;
	point->scale = 0;
	point->tmp = 0;
	check_size_col(point, utilities);
}

void				init_all_struct(t_utilities *utilities, t_events *events,
					char *argv)
{
	t_point		point;
	t_image		image;
	t_audio		audio;
	t_segment	segment;

	init_utilities(utilities);
	image.image_ptr = mlx_new_image(utilities->mlx_ptr, utilities->width,
						utilities->height);
	image.image_str = (int*)mlx_get_data_addr(image.image_ptr,
						&(image.bits_per_pixel), &(image.size_line),
						&(image.endian));
	init_point(utilities->fd, *utilities, &point);
	utilities->window_ptr = mlx_new_window(utilities->mlx_ptr, WIDTH, HEIGHT,
							"FdF");
	init_audio(utilities, &audio, argv);
	events->utilities = utilities;
	events->point = point;
	events->image = image;
	events->segment = &segment;
	events->audio = audio;
}

int					count_col(t_point *point)
{
	point->col_len = ft_strlen(point->tab[point->i]);
	point->col_len = ft_col_2d(point->col_len, point->tab[point->i]);
	return (point->col_len);
}

void				display_window(t_utilities utilities,
		t_point *point, t_image *image, t_segment segment)
{
	if (utilities.refresh == 0)
	{
		place_point(point, &utilities);
		place_iso_point(point, utilities);
	}
	draw_lines(point, &utilities, *image, segment);
	if (utilities.double_seg == 2)
	{
		utilities.double_seg = 1;
		draw_double_lines(point, &utilities, *image);
		utilities.double_seg = 2;
	}
	mlx_put_image_to_window(utilities.mlx_ptr, utilities.window_ptr,
	image->image_ptr, 0, 0);
	if (utilities.tool_bar == 1)
		display_tool_bar(&utilities);
}
