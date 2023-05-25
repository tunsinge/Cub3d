/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 02:13:02 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/25 09:48:00 by mdoumi           ###   ########.fr       */
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
	VAR->w = WINW;
	VAR->h = WINH;
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
