/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stock_param.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 11:13:04 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 20:58:18 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char		*stock_param(const int fd)
{
	char		*line;
	char		*tmp;
	char		*str;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || (read(fd, NULL, 0) == -1))
		return (0);
	line = NULL;
	str = ft_strnew(1);
	while ((ret = get_next_line_feed(fd, &line)) > 0)
	{
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	return (str);
}

static int		check_hexa_code(char **tab, int i, int j)
{
	while (tab[i][j] != ' ' && tab[i][j] != '\0')
	{
		if (ft_isdigit(tab[i][j]) == 1 || (tab[i][j] >= 65
			&& tab[i][j] <= 70) || (tab[i][j] >= 97 && tab[i][j] <= 102))
			j++;
		else
			return (0);
	}
	return (1);
}

char			**create_tab_2d(const int fd, char **tab)
{
	char		*str;

	str = stock_param(fd);
	tab = ft_strsplit(str, '\n');
	free(str);
	str = NULL;
	return (tab);
}

int				check_tab(char **tab)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 1 || tab[i][j] == ' ' ||
				(tab[i][j] == '-' && ft_isdigit(tab[i][j + 1]) == 1))
				j++;
			else if (tab[i][j] == ',' && tab[i][j + 1] == '0' &&
					(tab[i][j + 2] == 'x' || tab[i][j + 2] == 'X'))
			{
				j += 3;
				check_hexa_code(tab, i, j);
			}
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}
