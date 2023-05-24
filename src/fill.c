/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:19:00 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/23 10:19:00 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_cub3d *uwu)
{
	int	i;

	i = 0;
	while (uwu->map[i])
	{
		printf("%s\n", uwu->map[i]);
		i++;
	}
	printf("\n");
}

void	fill_map(t_cub3d *uwu)
{
	int	y;
	int	x;
	int	width;

	width = max_width(uwu);
	y = 0;
	while (uwu->map[y])
	{
		x = -1;
		while (uwu->map[y][++x])
			if (uwu->map[y][x] == ' ')
				uwu->map[y][x] = '0';
		while (ft_strlen(uwu->map[y]) < width)
			ft_strjoinfree(&uwu->map[y], "0");
		y++;
	}
}

int	max_width(t_cub3d *uwu)
{
	int	width;
	int	y;

	width = 0;
	y = 0;
	while (uwu->map[y])
	{
		if (ft_strlen(uwu->map[y]) > width)
			width = ft_strlen(uwu->map[y]);
		y++;
	}
	return (width);
}
