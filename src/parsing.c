/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:33:53 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/02 18:53:05 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**map_to_tab(char *path)
{
	int		fd;
	char	*buff;
	char	**map;

	fd = open(path, O_RDWR);
	if (fd == -1)
		return (error(OPEN_ERROR));
	map = malloc(sizeof(char *));
	map[0] = NULL;
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		map = append_to_map(buff, map);
		free(buff);
		buff = get_next_line(fd);
	}
	return (map);
}

char	**append_to_map(char *line, char **map)
{
	char	**map_tmp;
	int		i;

	//Regler ce malloc
	map_tmp = malloc(10000);
	i = -1;
	while (map[++i])
		map_tmp[i] = map[i];
	map_tmp[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	map_tmp[i][ft_strlen(map_tmp[i])] = '\0';
	map_tmp[++i] = NULL;
	return (map_tmp);
}
