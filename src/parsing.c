/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:33:53 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/02 16:49:53 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**map_to_tab(char *path)
{
	int		fd;
	char	*buff;
	char	**map = NULL;

	fd = open(path, O_RDWR);
	if (fd == -1)
		return (error(OPEN_ERROR));

	buff = get_next_line(fd);
	while (buff != NULL)
	{
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);

	return (map);
}
