/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coucou.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/20 17:55:59 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 13:34:12 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			check_end_str(t_segment *segment, t_utilities *utilities, t_point
							*point)
{
	if (segment->y <= 0 || segment->x <= 0 ||
		segment->j >= utilities->height * utilities->width ||
		(point->scale != 0 && segment->x > utilities->width))
		return (-1);
	else
		return (1);
}

int			check_fd(int fd)
{
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	else
		return (0);
}

int			check_name_file(char *argv, int argv_num)
{
	char	*str;
	int		i;
	int		j;

	if (argv_num == 1)
		str = "fdf.";
	if (argv_num == 2)
		str = "vaw.";
	i = ft_strlen(argv);
	j = 0;
	i -= 1;
	while ((size_t)i >= ft_strlen(argv) - 3)
	{
		if (argv[i] != str[j])
			return (-1);
		i--;
		j++;
	}
	return (1);
}

void		display_error_and_exit(int error)
{
	if (error == 1)
	{
		ft_putendl(ERROR);
		ft_putendl(USAGE_MAIN);
	}
	if (error == 2)
		ft_putendl(TOO_BIG);
	exit(EXIT_FAILURE);
}

void		check_size_col(t_point *point, t_utilities utilities)
{
	if (point->col_len >= 400)
	{
		utilities.error = 2;
		display_error_and_exit(utilities.error);
	}
	else if (point->col_len <= 12 && utilities.double_seg == 0)
		point->interval /= 1.5;
}
