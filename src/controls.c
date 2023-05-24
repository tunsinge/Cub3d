/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:56:53 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/24 19:39:56 by mdoumi           ###   ########.fr       */
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

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*uwu;

	uwu = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		quit_program();
	if (keydata.key == KEY_FORWARD && keydata.action == MLX_PRESS)
		uwu->keys.key_w = 1;
	if (keydata.key == KEY_BACKWARD && keydata.action == MLX_PRESS)
		uwu->keys.key_s = 1;
	if (keydata.key == MLX_KEY_LEFT_CONTROL && keydata.action == MLX_PRESS)
		uwu->keys.key_wi = 1;
	if (keydata.key == MLX_KEY_LEFT_CONTROL && keydata.action == MLX_RELEASE)
		uwu->keys.key_wi = 0;
	if (keydata.key == KEY_STRAF_RIGHT && keydata.action == MLX_PRESS)
		uwu->keys.key_d = 1;
	if (keydata.key == KEY_STRAF_LEFT && keydata.action == MLX_PRESS)
		uwu->keys.key_a = 1;
	if (keydata.key == KEY_ROTATE_LEFT && keydata.action == MLX_PRESS)
		uwu->keys.key_l = 1;
	if (keydata.key == KEY_ROTATE_RIGHT && keydata.action == MLX_PRESS)
		uwu->keys.key_r = 1;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		uwu->keys.key_shift = 1;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS && uwu->keys.key_jump == 0)
		uwu->keys.key_jump = 1;
	if (keydata.key == KEY_RUN && keydata.action == MLX_PRESS)
		uwu->keys.key_run = 1;
	if (keydata.key == KEY_FORWARD && keydata.action == MLX_RELEASE)
		uwu->keys.key_w = 0;
	if (keydata.key == KEY_BACKWARD && keydata.action == MLX_RELEASE)
		uwu->keys.key_s = 0;
	if (keydata.key == KEY_STRAF_RIGHT && keydata.action == MLX_RELEASE)
		uwu->keys.key_d = 0;
	if (keydata.key == KEY_STRAF_LEFT && keydata.action == MLX_RELEASE)
		uwu->keys.key_a = 0;
	if (keydata.key == KEY_ROTATE_LEFT && keydata.action == MLX_RELEASE)
		uwu->keys.key_l = 0;
	if (keydata.key == KEY_ROTATE_RIGHT && keydata.action == MLX_RELEASE)
		uwu->keys.key_r = 0;
	if (keydata.key == KEY_RUN && keydata.action == MLX_RELEASE)
		uwu->keys.key_run = 0;
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
	if (uwu->keys.key_wi == 1)
	{
		if (uwu->m_size < (256 / uwu->map_s_x) * 2)
		{
			uwu->m_size += 1;
			mlx_delete_image(uwu->mlx, uwu->map_img);
			init_map(uwu);
		}
	}
	else
	{
		if (uwu->m_size > 256 / uwu->map_s_x)
		{
			uwu->m_size -= 1;
			mlx_delete_image(uwu->mlx, uwu->map_img);
			init_map(uwu);
		}
	}
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

void	rotate(t_cub3d *uwu)
{
	int	pos[2];

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
	if (uwu->hehe < 5)
	{
		mlx_set_mouse_pos(uwu->mlx, windowWidth / 2, windowHeight / 2);
		return ;
	}
	mlx_get_mouse_pos(uwu->mlx, &pos[0], &pos[1]);
	if (pos[0] != windowWidth / 2)
	{
		uwu->pa += (pos[0] - windowWidth / 2) * 0.0005;
		check_angle(&uwu->pa);
		uwu->ray->pdx = cosf(uwu->pa) * 5;
		uwu->ray->pdy = sinf(uwu->pa) * 5;
		uwu->ray->pdxs = cosf(uwu->pa + P2) * 2;
		uwu->ray->pdys = sinf(uwu->pa + P2) * 2;
		mlx_set_mouse_pos(uwu->mlx, windowWidth / 2, windowHeight / 2);
	}
}
