/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:42:55 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/30 13:05:44 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_cub3d *uwu)
{
	if (uwu->keys.key_l != 0)
	{
		uwu->pa -= 0.05;
		if (uwu->pa < 0)
			uwu->pa += 2 * PI;
		uwu->ray->pdx = cosf(uwu->pa) * 5;
		uwu->ray->pdy = sinf(uwu->pa) * 5;
		uwu->ray->pdxs = cosf(uwu->pa + P2) * 2;
		uwu->ray->pdys = sinf(uwu->pa + P2) * 2;
	}
	if (uwu->keys.key_r != 0)
	{
		uwu->pa += 0.05;
		if (uwu->pa > 2 * PI)
			uwu->pa -= 2 * PI;
		uwu->ray->pdx = cosf(uwu->pa) * 5;
		uwu->ray->pdy = sinf(uwu->pa) * 5;
		uwu->ray->pdxs = cosf(uwu->pa + P2) * 2;
		uwu->ray->pdys = sinf(uwu->pa + P2) * 2;
	}
	mouse(uwu);
}

void	mouse(t_cub3d *uwu)
{
	int	pos[2];

	pos[0] = 0;
	pos[1] = 0;
	if (uwu->hehe < 5)
	{
		mlx_set_mouse_pos(uwu->mlx, WINW / 2, WINH / 2);
		return ;
	}
	mlx_get_mouse_pos(uwu->mlx, &pos[0], &pos[1]);
	if (pos[0] != WINW / 2)
	{
		uwu->pa += (pos[0] - WINW / 2) * 0.0005;
		check_angle(&uwu->pa);
		uwu->ray->pdx = cosf(uwu->pa) * 5;
		uwu->ray->pdy = sinf(uwu->pa) * 5;
		uwu->ray->pdxs = cosf(uwu->pa + P2) * 2;
		uwu->ray->pdys = sinf(uwu->pa + P2) * 2;
		mlx_set_mouse_pos(uwu->mlx, WINW / 2, WINH / 2);
	}
}

void	map_zoom(t_cub3d *uwu)
{
	if (uwu->keys.key_wi == 1)
	{
		if (uwu->m_size < uwu->m_fix_size * 2)
		{
			uwu->m_size += 1;
			mlx_delete_image(uwu->mlx, uwu->map_img);
			init_map(uwu);
		}
	}
	else
	{
		if (uwu->m_size > uwu->m_fix_size)
		{
			uwu->m_size -= 1;
			mlx_delete_image(uwu->mlx, uwu->map_img);
			init_map(uwu);
		}
	}
}

void	jump(t_cub3d *uwu)
{
	if (uwu->keys.key_jump != 0)
	{
		if (uwu->jumping < 100 && uwu->keys.key_jump == 1)
			uwu->jumping += (100 - uwu->jumping + 5) / 4;
		if (uwu->jumping >= 100)
			uwu->keys.key_jump = 2;
		if (uwu->jumping > 0 && uwu->keys.key_jump == 2)
			uwu->jumping -= (100 - uwu->jumping + 5) / 4;
		if (uwu->jumping <= 0)
		{
			uwu->jumping = 0;
			uwu->keys.key_jump = 0;
		}
	}
}
