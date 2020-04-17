/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 12:14:26 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 08:58:03 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_utilities	utilities;
	t_events	events;

	if (argc == 3)
	{
		utilities.fd = open(argv[1], O_RDONLY);
		if (check_fd(utilities.fd) == -1 || check_name_file(argv[1], 1) == -1 ||
			check_name_file(argv[2], 2) == -1)
		{
			utilities.error = 1;
			display_error_and_exit(utilities.error);
		}
		if (ft_strcmp(argv[1], "test_maps/oui.fdf") == 0)
			utilities.double_seg = 2;
		else if (ft_strcmp(argv[1], "test_maps/mars.fdf") == 0)
			utilities.double_seg = 3;
		init_all_struct(&utilities, &events, argv[2]);
		display_window(utilities, &events.point, &events.image,
						*events.segment);
		mlx_key_hook(utilities.window_ptr, manage_events, &events);
		mlx_loop(utilities.mlx_ptr);
	}
	else
		ft_putendl(USAGE_MAIN);
	return (0);
}
