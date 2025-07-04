/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:18:28 by mdoumi            #+#    #+#             */
/*   Updated: 2023/06/08 12:55:01 by mdoumi           ###   ########.fr       */
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
	int	k;

	i = -1;
	k = 0;
	while (uwu->map[++i])
	{
		j = -1;
		while (uwu->map[i][++j])
		{
			if (is_player(uwu->map[i][j]))
			{
				set_angle(uwu, uwu->map[i][j]);
				uwu->px = j;
				uwu->py = i;
				k++;
			}
		}
	}
	if (k < 1)
		return (error(NO_START_ERROR), 1);
	else if (k > 1)
		return (error(MUL_START_ERROR), 1);
	return (0);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	is_etranger_restrained(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == '4' || c == '3')
		return (0);
	return (1);
}
