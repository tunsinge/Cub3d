/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 02:13:02 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/25 11:25:45 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_col(mlx_image_t *img, int xy[2], int x, int color)
{
	int	i;

	i = xy[0] - 1;
	while (++i <= xy[1])
		mlx_put_pixel(img, x, i, color);
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
	uwu->ray->w = WINW;
	uwu->ray->h = WINH;
	uwu->ray->px = uwu->px;
	uwu->ray->py = uwu->py;
	uwu->ray->ra = uwu->pa - DR * 30;
	uwu->ray->pa = uwu->pa;
	check_angle(&uwu->ray->ra);
	uwu->ray->ray_nb = 480;
	uwu->ray->r = 0;
	while (uwu->ray->r < uwu->ray->ray_nb)
	{
		uwu->ray->is_door[0] = 0;
		uwu->ray->is_door[1] = 0;
		horizontal(uwu, uwu->ray);
		vertical(uwu, uwu->ray);
		orientation(uwu, uwu->ray, 1);
		setup(uwu);
		calculations(uwu);
		draw(uwu);
		uwu->ray->ra += DR * (60 / uwu->ray->ray_nb);
		check_angle(&uwu->ray->ra);
		uwu->ray->r++;
	}
}
