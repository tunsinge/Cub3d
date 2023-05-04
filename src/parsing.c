/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:33:53 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/04 09:52:05 by mdoumi           ###   ########.fr       */
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
	char	**fields;
	int		nb_parsed;

	nb_parsed = 0;
	while (nb_parsed < 6)
	{
		line = get_next_line(fd);
		if (line[0] != '\n')
		{
			fields = ft_split(line, ' ');
			if (ft_strrlen(fields) != 2)
				return ((void)error(INVALID_LINE), quit_program());
			nb_parsed++;
		}
		free(line);
	}
}

void	store_texture(t_cub3d *uwu, char **fields)
{
	if (ft_strcmp(fields[0], "NO") == 0)
		uwu->textures.texture_no = ft_strdup(fields[0]);
	if (ft_strcmp(fields[0], "SO") == 0)
		uwu->textures.texture_so = ft_strdup(fields[0]);
	if (ft_strcmp(fields[0], "EA") == 0)
		uwu->textures.texture_ea = ft_strdup(fields[0]);
	if (ft_strcmp(fields[0], "WE") == 0)
		uwu->textures.texture_we = ft_strdup(fields[0]);
}
