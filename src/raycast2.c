/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:37:55 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/23 09:37:55 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orientation(t_cub3d *uwu)
{
	VAR->shade = 1;
	if (VAR->dis_v < VAR->dis_h)
	{
		VAR->rx = VAR->vx;
		VAR->ry = VAR->vy;
		VAR->dist = VAR->dis_v;
		if (VAR->ra > P2 && VAR->ra < P3)
			VAR->texture = uwu->textures->text_we;
		else
			VAR->texture = uwu->textures->text_ea;
	}
	if (VAR->dis_v >= VAR->dis_h)
	{
		VAR->shade = 0.5;
		VAR->rx = VAR->hx;
		VAR->ry = VAR->hy;
		VAR->dist = VAR->dis_h;
		if (VAR->ra > PI)
			VAR->texture = uwu->textures->text_no;
		else
			VAR->texture = uwu->textures->text_so;
	}
}

void	setup(t_cub3d *uwu)
{
	VAR->ca = VAR->pa - VAR->ra;
	VAR->dist = VAR->dist * cosf(VAR->ca);
	check_angle(&VAR->ca);
	VAR->line_h = (uwu->map_s_x * VAR->h) / VAR->dist;
	VAR->sext = VAR->texture->width;
	VAR->seyt = VAR->texture->height;
	VAR->ty_step = VAR->seyt / (float)VAR->line_h;
	VAR->ty_off = 0;
}

void	calculations(t_cub3d *uwu)
{
	if (VAR->line_h > VAR->h)
	{
		VAR->ty_off = (VAR->line_h - VAR->h) / 2.0;
		VAR->line_h = VAR->h;
	}
	VAR->line_o = VAR->h / 2 - VAR->line_h / 2;
	VAR->ty = VAR->ty_step * VAR->ty_off;
	if (VAR->shade != 1)
	{
		VAR->tx = (int)(VAR->rx / (uwu->map_s_x / VAR->sext))
			% (int)VAR->sext;
		if (VAR->ra < PI)
			VAR->tx = VAR->sext - 1 - VAR->tx;
	}
	else
	{
		VAR->tx = (int)(VAR->ry / (uwu->map_s_x / VAR->sext))
			% (int)VAR->seyt;
		if (VAR->ra > P2 && VAR->ra < P3)
			VAR->tx = VAR->sext - 1 - VAR->tx;
	}
}

void	draw(t_cub3d *uwu)
{
	VAR->y = 0;
	while (VAR->y < VAR->line_h)
	{
		VAR->color = pixel_to_color(VAR->texture, VAR->tx, VAR->ty);
		VAR->z = 0;
		while (VAR->z < VAR->w / VAR->ray_nb)
			mlx_put_pixel(uwu->trwad_img,
				VAR->r * VAR->w / VAR->ray_nb + VAR->z++,
				VAR->line_o + VAR->y, VAR->color);
		VAR->ty += VAR->ty_step;
		VAR->y++;
	}
	VAR->z = 0;
	while (VAR->z < VAR->w / VAR->ray_nb)
	{
		draw_line(uwu->trwad_img, VAR->r * VAR->w / VAR->ray_nb + VAR->z,
			0, VAR->r * VAR->w / VAR->ray_nb + VAR->z,
			VAR->line_o, uwu->textures->color_ce);
		draw_line(uwu->trwad_img,
			VAR->r * VAR->w / VAR->ray_nb + VAR->z,
			VAR->line_h + VAR->line_o - 1, VAR->r * VAR->w / VAR->ray_nb
			+ VAR->z, VAR->h - 1,
			uwu->textures->color_fl);
		VAR->z++;
	}
}
