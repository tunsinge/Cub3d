/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:18:28 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/18 03:13:10 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_angle(t_cub3d *uwu, char c)
{
	if (c == 'N')
		uwu->pa = P2;
	if (c == 'S')
		uwu->pa = P3;
	if (c == 'E')
		uwu->pa = 0;
	if (c == 'W')
		uwu->pa = PI;
}

void	get_pp(t_cub3d *uwu)
{
	int	i;
	int	j;

	i = 0;
	while (uwu->map[i])
	{
		j = 0;
		while (uwu->map[i][j])
		{
			set_angle(uwu, uwu->map[i][j]);
			if (uwu->map[i][j] == 'N')
			{
				uwu->p_x = j;
				uwu->p_y = i;
			}
			j++;
		}
		i++;
	}
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
