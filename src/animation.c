/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:46:38 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/06/01 16:46:39 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*todo
 * adapter affichage texture pour rick -> changer pixel to color
 * reduire vitesse animation rick
 * mise carte a 2 tir
 * affichage rick sur 2
 * */

void	rick_load_texture(t_cub3d *uwu)
{
	uwu->t->current_x = 0;
	uwu->t->rick_full = mlx_load_png("textures/texture.png");
}

int	rick_pixel_to_color(t_cub3d *uwu, uint32_t x, uint32_t y)
{
	uint8_t			*pixel;
	uint32_t		color;
	uint32_t		wh[2];
	mlx_texture_t	*text;

	text = uwu->t->rick_full;
	wh[0] = 498 + uwu->t->current_x;
	wh[1] = 427;
	if (x > uwu->t->rick_full->width || y > wh[1])
		return (0x000000FF);
	pixel = &text->pixels[(y * uwu->t->rick_full->width + x + uwu->t->current_x)
		* text->bytes_per_pixel];
	color = (pixel[0] << 24) + (pixel[1] << 16) + (pixel[2] << 8) + pixel[3];
	return (color);
}

void	rick_next(t_cub3d *uwu)
{
	uwu->t->current_x += 498;
	if (uwu->t->current_x > uwu->t->rick_full->width)
		uwu->t->current_x = 0;
}

void	set_texture_size(t_cub3d *uwu)
{
	uwu->ray->sext = uwu->ray->t->width;
	uwu->ray->seyt = uwu->ray->t->height;
	if (uwu->ray->is_door == 2)
	{
		uwu->ray->sext = 498;
		uwu->ray->seyt = 427;
	}
}
