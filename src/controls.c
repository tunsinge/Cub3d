/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:56:53 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/23 11:56:53 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_controls(t_cub3d *uwu)
{
	uwu->keys.key_w = 0;
	uwu->keys.key_a = 0;
	uwu->keys.key_s = 0;
	uwu->keys.key_d = 0;
	uwu->keys.key_r = 0;
	uwu->keys.key_l = 0;
	uwu->keys.key_shift = 0;
}

void	controls_hook(void *param)
{
	t_cub3d	*uwu;

	uwu = param;
	if (uwu->keys.key_shift)
		uwu->speed = 1.5;
	else
		uwu->speed = 0.25;
	move(uwu);
	rotate(uwu);
	render(uwu);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*uwu;

	uwu = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		quit_program();
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		uwu->keys.key_w = 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		uwu->keys.key_s = 1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		uwu->keys.key_d = 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		uwu->keys.key_a = 1;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		uwu->keys.key_l = 1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		uwu->keys.key_r = 1;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		uwu->keys.key_shift = 1;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		uwu->keys.key_w = 0;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		uwu->keys.key_s = 0;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		uwu->keys.key_d = 0;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		uwu->keys.key_a = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		uwu->keys.key_l = 0;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		uwu->keys.key_r = 0;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
		uwu->keys.key_shift = 0;
}

void	move(t_cub3d *uwu)
{
	if (uwu->keys.key_w != 0)
	{
		move_x(uwu, uwu->ray->pdx);
		move_y(uwu, uwu->ray->pdy);
	}
	if (uwu->keys.key_s != 0)
	{
		move_x(uwu, -uwu->ray->pdx);
		move_y(uwu, -uwu->ray->pdy);
	}
	if (uwu->keys.key_d != 0)
	{
		move_x(uwu, uwu->ray->pdxs);
		move_y(uwu, uwu->ray->pdys);
	}
	if (uwu->keys.key_a != 0)
	{
		move_x(uwu, -uwu->ray->pdxs);
		move_y(uwu, -uwu->ray->pdys);
	}
}

void	rotate(t_cub3d *uwu)
{
	if (uwu->keys.key_l != 0)
	{
		uwu->pa -= 0.05;
		if (uwu->pa < 0)
			uwu->pa += 2 * PI;
		uwu->ray->pdx = cosf(uwu->pa) * 5;
		uwu->ray->pdy = sinf(uwu->pa) * 5;
		uwu->ray->pdxs = cosf(uwu->pa + P2) * 5;
		uwu->ray->pdys = sinf(uwu->pa + P2) * 5;
	}
	if (uwu->keys.key_r != 0)
	{
		uwu->pa += 0.05;
		if (uwu->pa > 2 * PI)
			uwu->pa -= 2 * PI;
		uwu->ray->pdx = cosf(uwu->pa) * 5;
		uwu->ray->pdy = sinf(uwu->pa) * 5;
		uwu->ray->pdxs = cosf(uwu->pa + P2) * 5;
		uwu->ray->pdys = sinf(uwu->pa + P2) * 5;
	}
}
