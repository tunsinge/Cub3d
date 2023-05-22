/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:40:51 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/18 15:04:10 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_etranger(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ')
		return (0);
	return (1);
}

void	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_etranger(map[i][j]))
				error(ETRANGER_ERROR);
			j++;
		}
		i++;
	}
}

void	check_map_path(char **av)
{
	char	*s;

	s = ft_substr(av[1], ft_strlen(av[1]) - 4, ft_strlen(av[1]));
	if (ft_strcmp(s, ".cub") != 0)
		error(INVALID_PATH);
	free(s);
}

int	check_map_closed(t_cub3d *uwu)
{
	int	i;
	int	j;

	i = -1;
	while (uwu->map[++i])
	{
		j = 0;
		while (uwu->map[i][j])
		{
			if (uwu->map[i][j] == '0')
			{
				if (i - 1 < 0 || j - 1 < 0
					|| i + 1 >= uwu->map_s_y || j + 1 >= uwu->map_s_x
					|| uwu->map[i + 1][j] == ' '
					|| uwu->map[i - 1][j] == ' '
					|| uwu->map[i][j + 1] == ' '
					|| uwu->map[i][j - 1] == ' ')
					return (error(NOT_CLOSED_MAP), 0);
			}
			j++;
		}
	}
	return (1);
}
