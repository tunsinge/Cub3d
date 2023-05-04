/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:18:28 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/04 12:18:51 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
