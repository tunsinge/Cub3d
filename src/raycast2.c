/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:37:55 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/06/09 15:06:44 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orientation(t_cub3d *uwu, t_ray *rays, int t)
{
	rays->shade = 1;
	if (rays->dis_v < rays->dis_h)
	{
		rays->rx = rays->vx;
		rays->ry = rays->vy;
		rays->dist = rays->dis_v;
		if (t)
			pick_textures(uwu, rays->ra > P2 && rays->ra < P3, 1);
	}
	if (rays->dis_v >= rays->dis_h)
	{
		rays->shade = 0.5;
		rays->rx = rays->hx;
		rays->ry = rays->hy;
		rays->dist = rays->dis_h;
		if (t)
			pick_textures(uwu, rays->ra > PI, 0);
	}
}

void	setup(t_cub3d *uwu)
{
	uwu->ray->ca = uwu->ray->pa - uwu->ray->ra;
	uwu->ray->dist = uwu->ray->dist * cosf(uwu->ray->ca);
	check_angle(&uwu->ray->ca);
	uwu->ray->line_h = (uwu->map_s * uwu->ray->h) / uwu->ray->dist;
	uwu->ray->ty_step = uwu->ray->seyt / (float)uwu->ray->line_h;
	uwu->ray->ty_off = 0;
}

void	calculations(t_cub3d *uwu)
{
	if (uwu->ray->line_h > uwu->ray->h)
	{
		uwu->ray->ty_off = (uwu->ray->line_h - uwu->ray->h) / 2.0;
		uwu->ray->line_h = uwu->ray->h;
	}
	uwu->ray->line_o = (uwu->ray->h / 2 - uwu->ray->line_h / 2) + uwu->jumping;
	uwu->ray->ty = uwu->ray->ty_step * uwu->ray->ty_off;
	if (uwu->ray->shade != 1)
	{
		uwu->ray->tx = (int)(uwu->ray->rx / (uwu->map_s / uwu->ray->sext))
			% (int)uwu->ray->sext;
		if (uwu->ray->ra < PI)
			uwu->ray->tx = uwu->ray->sext - 1 - uwu->ray->tx;
	}
	else
	{
		uwu->ray->tx = (int)(uwu->ray->ry / (uwu->map_s / uwu->ray->sext))
			% (int)uwu->ray->sext;
		if (uwu->ray->ra > P2 && uwu->ray->ra < P3)
			uwu->ray->tx = uwu->ray->sext - 1 - uwu->ray->tx;
	}
}

void	draw(t_cub3d *uwu)
{
	uwu->ray->y = -1;
	while (++uwu->ray->y < uwu->ray->line_h)
	{
		uwu->ray->c = pixel_to_color(uwu, uwu->ray->tx, uwu->ray->ty);
		uwu->ray->z = 0;
		while (uwu->ray->z < uwu->ray->w / uwu->ray->ray_nb)
			mlx_put_pixel(uwu->trwad_img,
				uwu->ray->r * uwu->ray->w / uwu->ray->ray_nb + uwu->ray->z++,
				uwu->ray->line_o + uwu->ray->y, uwu->ray->c);
		uwu->ray->ty += uwu->ray->ty_step;
	}
	uwu->ray->z = -1;
	while (++uwu->ray->z < uwu->ray->w / uwu->ray->ray_nb)
	{
		((void)0, uwu->ray->xy[0] = 0, uwu->ray->xy[1] = uwu->ray->line_o);
		draw_col(uwu->trwad_img, uwu->ray->xy, uwu->ray->r * uwu->ray->w
			/ uwu->ray->ray_nb + uwu->ray->z, uwu->t->ce);
		if (uwu->ray->line_o + uwu->ray->line_h - 1 > WINH)
			uwu->ray->line_h = WINH - uwu->ray->line_o;
		uwu->ray->xy[0] = uwu->ray->line_h + uwu->ray->line_o - 1;
		uwu->ray->xy[1] = uwu->ray->h + 200 - 1;
		draw_col(uwu->trwad_img, uwu->ray->xy,
			uwu->ray->r * uwu->ray->w / uwu->ray->ray_nb + uwu->ray->z,
			uwu->t->fl);
	}
}
