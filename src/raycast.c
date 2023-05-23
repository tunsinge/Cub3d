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
		orientation(uwu);
		setup(uwu);
		calculations(uwu);
		draw(uwu);
		VAR->ra += DR * (60 / VAR->ray_nb);
		check_angle(&VAR->ra);
		VAR->r++;
	}
}
