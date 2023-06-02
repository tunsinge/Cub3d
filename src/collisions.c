/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:41:42 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/30 13:27:50 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_x(t_cub3d *uwu, float dx)
{
	float	nb;

	nb = uwu->px + dx * uwu->speed + (uwu->p_size / 2 + 1) * (dx > 0);
	if (uwu->map[(int)uwu->py / uwu->map_s][(int)nb / uwu->map_s] == '1')
		return ;
	else if (uwu->map[(int)uwu->py / uwu->map_s][(int)nb / uwu->map_s] == '4')
	{
		return ;
	}
	uwu->px += dx * uwu->speed;
}

void	move_y(t_cub3d *uwu, float dy)
{
	float	nb;

	nb = uwu->py + dy * uwu->speed + (uwu->p_size / 2 + 1) * (dy > 0);
	if (uwu->map[(int)nb / uwu->map_s][(int)uwu->px / uwu->map_s] == '1')
		return ;
	uwu->py += dy * uwu->speed;
}
