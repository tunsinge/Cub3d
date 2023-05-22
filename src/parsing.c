/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:33:53 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/04 12:18:12 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**parse_map(t_cub3d *uwu, char *path)
{
	int		fd;
	char	*buff;
	char	**map;

	fd = open(path, O_RDWR);
	if (fd == -1)
		return (error(OPEN_ERROR));
	map = malloc(sizeof(char *));
	parse_textures(uwu, fd);
	map[0] = NULL;
	buff = get_next_line(fd);
	while (buff[0] == '\n')
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

	map_tmp = malloc(sizeof(char *) * (ft_strrlen(map) + 2));
	i = -1;
	while (map[++i])
		map_tmp[i] = map[i];
	map_tmp[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	map_tmp[i][ft_strlen(map_tmp[i])] = '\0';
	map_tmp[++i] = NULL;
	free(map);
	return (map_tmp);
}

void	parse_textures(t_cub3d *uwu, int fd)
{
	char	*line;
	char	*line_nonl;
	char	**fields;
	int		nb_parsed;

	nb_parsed = 0;
	while (nb_parsed < 6)
	{
		line = get_next_line(fd);
		if (line[0] != '\n')
		{
			line_nonl = ft_strdupnonl(line);
			fields = ft_split(line_nonl, ' ');
			if (ft_strrlen(fields) != 2)
				return ((void)error(INVALID_LINE), quit_program());
			store_texture(uwu, fields);
			nb_parsed++;
			free_s(fields);
			free(line_nonl);
		}
		free(line);
	}
}

t_case	***tab_to_struct(t_cub3d *uwu)
{
	int		i;
	int		j;
	t_case	***tab;

	i = 0;
	tab = malloc(sizeof(t_case **) * (ft_strrlen(uwu->map) + 2));
	while (uwu->map[i])
	{
		j = 0;
		tab[i] = malloc(sizeof(t_case *) * (ft_strlen(uwu->map[i]) + 1));
		while (uwu->map[i][j])
		{
			tab[i][j] = malloc(sizeof(t_case));
			tab[i][j]->value = uwu->map[i][j];
			j++;
		}
		tab[i][j] = NULL;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
