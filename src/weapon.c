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

	uwu->t->weapon_text = mlx_load_png("./textures/weapon.png");
	uwu->t->weapon_current = 0;
	uwu->t->weapon_width = 175;
	uwu->t->weapon_height = 275;
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

	uwu->t->weapon_current += uwu->t->weapon_width;
	xy[0] = uwu->t->weapon_current;
	xy[1] = 0;
	wh[0] = uwu->t->weapon_width;
	wh[1] = uwu->t->weapon_height;
	mlx_delete_image(uwu->mlx, uwu->t->weapon_img);
	uwu->t->weapon_img = mlx_texture_area_to_image(uwu->mlx,
			uwu->t->weapon_text, xy, wh);
}

void	shoot(t_cub3d *uwu)
{
	int	i;

	while (uwu->t->weapon_current < uwu->t->weapon_text->width)
	{
		i = 0;
		while (i < 50)
			i++;
		weapon_next_image(uwu);
	}
	uwu->t->weapon_current = 0;
	weapon_next_image(uwu);
}
