/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 02:13:02 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/22 15:36:25 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
{
	t_drwlvars	v;

	v.sx = (x0 < x1) + (x0 >= x1) * -1;
	v.sy = (y0 < y1) + (y0 >= y1) * -1;
	v.err = abs(x1 - x0);
	if (abs(x1 - x0) <= abs(y1 - y0))
		v.err = -abs(y1 - y0);
	while (1)
	{
		if (x0 >= 0 && x0 <= windowWidth && y0 >= 0 && y0 <= windowHeight)
			mlx_put_pixel(img, x0, y0, color);
		else
			return ;
		if (x0 == x1 && y0 == y1)
			return ;
		v.e2 = v.err;
		if (v.e2 > -abs(x1 - x0))
			((void)0, v.err -= abs(y1 - y0), x0 += v.sx);
		if (v.e2 < abs(y1 - y0))
			((void)0, v.err += abs(x1 - x0), y0 += v.sy);
	}
}

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	check_angle(float *ra)
{
	if (*ra < 0)
		*ra += 2 * PI;
	if (*ra > 2 * PI)
		*ra -= 2 * PI;
}

void	raycaster(t_cub3d *uwu)
{
	mlx_texture_t	*texture;

	VAR->w = 480 * scale;
	VAR->h = 320 * scale;
	VAR->px = uwu->px + uwu->p_size / 2;
	VAR->py = uwu->py + uwu->p_size / 2;
	VAR->ra = uwu->pa - DR * 30;
	VAR->pa = uwu->pa;
	check_angle(&VAR->ra);
	VAR->ray_nb = 480;
	VAR->r = 0;
	while (VAR->r < VAR->ray_nb)
	{
		horizontal(uwu);
		vertical(uwu);
		VAR->shade = 1;
		if (VAR->dis_v < VAR->dis_h)
		{
			VAR->rx = VAR->vx;
			VAR->ry = VAR->vy;
			VAR->dist = VAR->dis_v;
			if (VAR->ra > P2 && VAR->ra < P3)
				texture = uwu->textures->text_we;
			else
				texture = uwu->textures->text_ea;
		}
		if (VAR->dis_v >= VAR->dis_h)
		{
			VAR->shade = 0.5;
			VAR->rx = VAR->hx;
			VAR->ry = VAR->hy;
			VAR->dist = VAR->dis_h;
			if (VAR->ra > PI)
				texture = uwu->textures->text_no;
			else
				texture = uwu->textures->text_so;
		}
		VAR->ca = VAR->pa - VAR->ra;
		VAR->dist = VAR->dist * cosf(VAR->ca);
		check_angle(&VAR->ca);
		VAR->line_h = (uwu->m_size * VAR->h) / VAR->dist;
		VAR->sext = uwu->textures->text_no->width;
		VAR->seyt = uwu->textures->text_no->height;
		VAR->ty_step = VAR->seyt / (float)VAR->line_h;
		VAR->ty_off = 0;
		if (VAR->line_h > VAR->h)
		{
			VAR->ty_off = (VAR->line_h - VAR->h) / 2.0;
			VAR->line_h = VAR->h;
		}
		VAR->line_o = VAR->h / 2 - VAR->line_h / 2;
		VAR->ty = VAR->ty_step * VAR->ty_off;
		if (VAR->shade != 1)
		{
			VAR->tx = (int)(VAR->rx / (uwu->m_size / VAR->sext))
				% (int)VAR->sext;
			if (VAR->ra < PI)
				VAR->tx = VAR->sext - 1 - VAR->tx;
		}
		else
		{
			VAR->tx = (int)(VAR->ry / (uwu->m_size / VAR->sext))
				% (int)VAR->seyt;
			if (VAR->ra > P2 && VAR->ra < P3)
				VAR->tx = VAR->sext - 1 - VAR->tx;
		}
		VAR->y = 0;
		while (VAR->y < VAR->line_h)
		{
			VAR->color = pixel_to_color(texture, VAR->tx, VAR->ty);
			VAR->z = 0;
			while (VAR->z < VAR->w / VAR->ray_nb)
				mlx_put_pixel(uwu->trwaD_img,
					VAR->r * VAR->w / VAR->ray_nb + VAR->z++,
					VAR->line_o + VAR->y, VAR->color);
			VAR->ty += VAR->ty_step;
			VAR->y++;
		}
		VAR->z = 0;
		while (VAR->z < VAR->w / VAR->ray_nb)
		{
			draw_line(uwu->trwaD_img, VAR->r * VAR->w / VAR->ray_nb + VAR->z,
				0, VAR->r * VAR->w / VAR->ray_nb + VAR->z,
				VAR->line_o, uwu->textures->color_ce);
			draw_line(uwu->trwaD_img, VAR->r * VAR->w / VAR->ray_nb + VAR->z,
				VAR->line_h + VAR->line_o, VAR->r * VAR->w / VAR->ray_nb
				+ VAR->z, VAR->h - 1, uwu->textures->color_fl);
			VAR->z++;
		}
		VAR->ra += DR * (60 / VAR->ray_nb);
		check_angle(&VAR->ra);
		VAR->r++;
	}
}
