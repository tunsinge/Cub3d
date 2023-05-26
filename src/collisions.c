/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:41:42 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/24 20:41:59 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_x(t_cub3d *uwu, float dx)
{
	float	nb;

	nb = uwu->px + dx * uwu->speed + 5 * (dx > 0);
	if (uwu->map[(int)uwu->py / uwu->map_s_x][(int)nb / uwu->map_s_x] == '1')
		return ;
	uwu->px += dx * uwu->speed;
}

void	move_y(t_cub3d *uwu, float dy)
{
	float	nb;

	nb = uwu->py + dy * uwu->speed + 5 * (dy > 0);
	if (uwu->map[(int)nb / uwu->map_s_x][(int)uwu->px / uwu->map_s_x] == '1')
		return ;
	uwu->py += dy * uwu->speed;
}
