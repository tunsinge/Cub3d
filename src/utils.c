/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:18:28 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/18 15:04:49 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_angle(t_cub3d *uwu, char c)
{
	if (c == 'N')
		uwu->pa = P3;
	if (c == 'S')
		uwu->pa = P2;
	if (c == 'E')
		uwu->pa = 0;
	if (c == 'W')
		uwu->pa = PI;
}

int	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

int	get_pp(t_cub3d *uwu)
{
	int	i;
	int	j;

	i = 0;
	uwu->px = -1;
	uwu->py = -1;
	while (uwu->map[i])
	{
		j = 0;
		while (uwu->map[i][j])
		{
			if (is_player(uwu->map[i][j]))
			{
				set_angle(uwu, uwu->map[i][j]);
				uwu->px = j;
				uwu->py = i;
			}
			j++;
		}
		i++;
	}
	if (uwu->px == -1 || uwu->py == -1)
		return (error(NO_START_ERROR), 1);
	return (0);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
