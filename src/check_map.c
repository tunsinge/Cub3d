/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:40:51 by mdoumi            #+#    #+#             */
/*   Updated: 2023/06/08 13:12:22 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_etranger(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '4' || c == '3')
		return (0);
	return (1);
}

int	check_map(char **map)
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
				return (error(ETRANGER_ERROR), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_path(char **av)
{
	char	*s;
	int		e;

	e = 0;
	s = ft_substr(av[1], ft_strlen(av[1]) - 4, ft_strlen(av[1]));
	if (ft_strcmp(s, ".cub") != 0)
	{
		error(INVALID_PATH);
		e = 1;
	}
	free(s);
	return (e);
}

int	check_map_closed(t_cub3d *uwu)
{
	int	i;
	int	j;
	int	max;

	max = find_map_width(uwu);
	i = -1;
	while (uwu->map[++i])
	{
		j = -1;
		while (uwu->map[i][++j])
		{
			if (is_transparent(uwu->map[i][j])
				|| is_player(uwu->map[i][j]) || uwu->map[i][j] == '4')
			{
				if (i - 1 < 0 || j - 1 < 0
					|| i + 1 >= uwu->map_s_y || j + 1 >= max
					|| is_etranger_restrained(uwu->map[i + 1][j])
					|| is_etranger_restrained(uwu->map[i - 1][j])
					|| is_etranger_restrained(uwu->map[i][j + 1])
					|| is_etranger_restrained(uwu->map[i][j - 1]))
					return (error(NOT_CLOSED_MAP), quit_program(uwu, 1), 0);
			}
		}
	}
	return (1);
}

int	find_map_width(t_cub3d *uwu)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (uwu->map && uwu->map[i])
	{
		if (ft_strlen(uwu->map[i]) > max)
			max = ft_strlen(uwu->map[i]);
		i++;
	}
	return (max);
}
