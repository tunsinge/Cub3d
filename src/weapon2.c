/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:26:05 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/06/10 09:26:05 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	portal_load(t_cub3d *uwu)
{
	uwu->t->portal_text = mlx_load_png("./textures/portal.png");
	uwu->t->portal_img = mlx_texture_to_image(uwu->mlx, uwu->t->portal_text);
}

void	display_weapon(t_cub3d *uwu)
{
	if (uwu->t->current_weapon == 2)
	{
		mlx_image_to_window(uwu->mlx, uwu->t->weapon_img,
			WINW - uwu->t->weapon_width - 250,
			WINH - uwu->t->weapon_height);
	}
}

void	change_weapon(t_cub3d *uwu)
{
	if (uwu->t->current_weapon == 2)
	{
		uwu->t->current_weapon = 4;
		mlx_delete_image(uwu->mlx, uwu->t->weapon_img);
		uwu->t->weapon_img = NULL;
		mlx_delete_texture(uwu->t->portal_text);
		portal_load(uwu);
		mlx_image_to_window(uwu->mlx, uwu->t->portal_img,
			WINW - uwu->t->portal_text->width - 250,
			WINH - uwu->t->portal_text->height);
	}
	else
	{
		uwu->t->current_weapon = 2;
		mlx_delete_image(uwu->mlx, uwu->t->portal_img);
		uwu->t->weapon_current = 0;
		mlx_delete_texture(uwu->t->weapon_text);
		weapon_load(uwu);
		display_weapon(uwu);
	}
}

void	delete_weapons(t_cub3d *uwu)
{
	if (uwu->t->weapon_text)
		mlx_delete_texture(uwu->t->weapon_text);
	if (uwu->t->portal_text)
		mlx_delete_texture(uwu->t->portal_text);
}
