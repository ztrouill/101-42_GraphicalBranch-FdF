/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tool_bar.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 17:02:01 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 12:18:17 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			display_cross(t_utilities utilities, int x, int y)
{
	mlx_string_put(utilities.mlx_ptr, utilities.window_ptr, x, y,
	utilities.palette[0], ICONE_LR);
	x += 15;
	mlx_string_put(utilities.mlx_ptr, utilities.window_ptr, x, y - 10,
	utilities.palette[0], ICONE_UP_1);
	mlx_string_put(utilities.mlx_ptr, utilities.window_ptr, x, y,
	utilities.palette[0], ICONE_UP_2);
	mlx_string_put(utilities.mlx_ptr, utilities.window_ptr, x, y + 12,
	utilities.palette[0], ICONE_DOWN);
}

void				display_tool_bar(t_utilities *utilities)
{
	mlx_string_put(utilities->mlx_ptr, utilities->window_ptr, 155,
	utilities->height - 100, utilities->palette[1], TEXT_1);
	mlx_string_put(utilities->mlx_ptr, utilities->window_ptr, 685,
	utilities->height - 100, utilities->palette[1], TEXT_2);
	mlx_string_put(utilities->mlx_ptr, utilities->window_ptr, 145,
	utilities->height - 60, utilities->palette[1], TEXT_3);
	mlx_string_put(utilities->mlx_ptr, utilities->window_ptr, 155,
	utilities->height - 100, utilities->palette[0], ICONE_1);
	mlx_string_put(utilities->mlx_ptr, utilities->window_ptr, 145,
	utilities->height - 60, utilities->palette[0], ICONE_2);
	mlx_string_put(utilities->mlx_ptr, utilities->window_ptr, 155,
	utilities->height - 100, WHITE, OR_1);
	mlx_string_put(utilities->mlx_ptr, utilities->window_ptr, 935,
	utilities->height - 100, WHITE, OR_2);
	mlx_string_put(utilities->mlx_ptr, utilities->window_ptr, 125,
	utilities->height - 60, WHITE, OR_3);
	display_cross(*utilities, 968, utilities->height - 100);
}
