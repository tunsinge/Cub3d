/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:33:42 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/24 20:34:13 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx_image_to_window(uwu->mlx, uwu->t->weapon_img,
		WINW - wh[0] - 250, WINH - wh[1]);
}

void	weapon_next_image(t_cub3d *uwu)
{
	uint32_t	xy[2];
	uint32_t	wh[2];

	xy[0] = uwu->t->weapon_current;
	xy[1] = 0;
	wh[0] = uwu->t->weapon_width;
	wh[1] = uwu->t->weapon_height;
	mlx_delete_image(uwu->mlx, uwu->t->weapon_img);
	uwu->t->weapon_img = mlx_texture_area_to_image(uwu->mlx,
			uwu->t->weapon_text, xy, wh);
	mlx_image_to_window(uwu->mlx, uwu->t->weapon_img,
		WINW - wh[0] - 250, WINH - wh[1]);
	uwu->t->weapon_current += uwu->t->weapon_width;
}

void	shoot(t_cub3d *uwu)
{
	static int i = 0;

	if (uwu->keys.key_shoot)
	{
		if (i != 4)
			return (void)i++;
		i = 0;
		if (uwu->t->weapon_current <= uwu->t->weapon_text->width)
			weapon_next_image(uwu);
		else
		{
			uwu->keys.key_shoot = 0;
			uwu->t->weapon_current = 0;
		}
	}
}
