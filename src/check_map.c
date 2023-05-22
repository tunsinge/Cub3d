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
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
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
	char *s;

	s = ft_substr(av[1], ft_strlen(av[1]) - 4, ft_strlen(av[1]));
	if (ft_strcmp(s, ".cub") != 0)
		printf("Error\nMap is not valid. It must end with .cub.\n");
	free(s);
}
