/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:33:42 by mdoumi            #+#    #+#             */
/*   Updated: 2023/06/09 15:05:53 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_weapons(t_cub3d *uwu)
{
	uwu->t->current_weapon = 2;
	weapon_load(uwu);
	portal_load(uwu);
	display_weapon(uwu);
}

void	weapon_load(t_cub3d *uwu)
{
	uint32_t	xy[2];
	uint32_t	wh[2];

	uwu->t->weapon_text = mlx_load_png("./textures/weapon_sheet.png");
	uwu->t->weapon_current = 0;
	uwu->t->weapon_width = 155;
	uwu->t->weapon_height = 260;
	xy[0] = 0;
	xy[1] = 0;
	wh[0] = uwu->t->weapon_width;
	wh[1] = uwu->t->weapon_height;
	uwu->t->weapon_img = mlx_texture_area_to_image(uwu->mlx,
			uwu->t->weapon_text, xy, wh);
}

void	weapon_next_image(t_cub3d *uwu)
{
	uint32_t	xy[2];
	uint32_t	wh[2];

	xy[0] = uwu->t->weapon_current;
	xy[1] = 0;
	wh[0] = uwu->t->weapon_width;
	wh[1] = uwu->t->weapon_height;
	if (uwu->t->weapon_img)
		mlx_delete_image(uwu->mlx, uwu->t->weapon_img);
	uwu->t->weapon_img = mlx_texture_area_to_image(uwu->mlx,
			uwu->t->weapon_text, xy, wh);
	uwu->t->weapon_current += uwu->t->weapon_width;
	display_weapon(uwu);
}

void	shoot(t_cub3d *uwu)
{
	static int	i = 0;
	static int	s = 0;

	if (uwu->keys.key_shoot)
	{
		if (!s)
			one_ray(uwu);
		s = 1;
		if (i != 1)
			return ((void)i++);
		i = 0;
		if (uwu->t->weapon_current <= uwu->t->weapon_text->width)
			weapon_next_image(uwu);
		else
		{
			uwu->keys.key_shoot = 0;
			uwu->t->weapon_current = 0;
			s = 0;
		}
		mlx_delete_image(uwu->mlx, uwu->map_img);
		init_map(uwu);
	}
}

void	one_ray(t_cub3d *uwu)
{
	t_ray	rays;
	int		x;
	int		y;

	rays.w = WINW;
	rays.h = WINH;
	rays.px = uwu->ray->px;
	rays.py = uwu->ray->py;
	rays.ra = uwu->ray->pa;
	rays.pa = uwu->ray->pa;
	check_angle(&rays.ra);
	rays.ray_nb = 1;
	rays.r = 0;
	rays.is_door[0] = 0;
	rays.is_door[1] = 0;
	horizontal(uwu, &rays);
	vertical(uwu, &rays);
	orientation(uwu, &rays, 0);
	x = (int)(rays.rx) / uwu->map_s;
	y = (int)(rays.ry) / uwu->map_s;
	uwu->map[y][x] = '0' + uwu->t->current_weapon;
}
