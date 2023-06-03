/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:56:53 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/26 10:29:28 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_controls(t_cub3d *uwu)
{
	uwu->keys.key_w = 0;
	uwu->keys.key_a = 0;
	uwu->keys.key_s = 0;
	uwu->keys.key_d = 0;
	uwu->keys.key_e = 0;
	uwu->keys.key_r = 0;
	uwu->keys.key_l = 0;
	uwu->keys.key_wi = 0;
	uwu->keys.key_jump = 0;
	uwu->keys.key_shift = 0;
}

void	controls_hook(void *param)
{
	t_cub3d	*uwu;

	uwu = param;
	uwu->hehe++;
	if (uwu->keys.key_shift)
		uwu->speed = S_SPEED;
	else
		uwu->speed = N_SPEED;
	rotate(uwu);
	move(uwu);
	render(uwu);
}

void	set_key(mlx_key_data_t keydata, keys_t key, int *value)
{
	if (keydata.key == key && keydata.action == MLX_PRESS)
		*value = 1;
	if (keydata.key == key && keydata.action == MLX_RELEASE)
		*value = 0;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*uwu;

	uwu = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		quit_program(uwu);
	set_key(keydata, KEY_FORWARD, &uwu->keys.key_w);
	set_key(keydata, KEY_BACKWARD, &uwu->keys.key_s);
	set_key(keydata, KEY_STRAF_RIGHT, &uwu->keys.key_d);
	set_key(keydata, KEY_STRAF_LEFT, &uwu->keys.key_a);
	set_key(keydata, KEY_OPEN_DOOR, &uwu->keys.key_e);
	set_key(keydata, KEY_ROTATE_LEFT, &uwu->keys.key_l);
	set_key(keydata, KEY_ROTATE_RIGHT, &uwu->keys.key_r);
	set_key(keydata, KEY_ZOOM_MAP, &uwu->keys.key_wi);
	set_key(keydata, KEY_RUN, &uwu->keys.key_shift);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS
		&& uwu->keys.key_jump == 0)
		uwu->keys.key_jump = 1;
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
	open_doors(uwu);
	map_zoom(uwu);
	jump(uwu);
}
