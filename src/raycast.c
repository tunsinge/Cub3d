/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 02:13:02 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/19 18:56:10 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mapX = 8, mapY = 5, mapS = 64;

void	draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
{
	int dx;
	int dy;
	int err;
	int e2;
	int	sx;
	int	sy;

	dx = abs(x1-x0);
	sx = x0<x1 ? 1 : -1;
	dy = abs(y1-y0);
	sy = y0<y1 ? 1 : -1;
	err = (dx>dy ? dx : -dy)/2;

	while (1)
	{
		if (x0 >= 0 && x0 <= windowWidth && y0 >= 0 && y0 <= windowHeight)
			mlx_put_pixel(img, x0, y0, color);
		else
			return ;
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void	raycaster(t_cub3d *uwu)
{
	float	px, py, rx, ry, ra, xo, yo;
	int		r,mx,my,mp,dof;

	px = uwu->px + uwu->p_size / 2;
	py = uwu->py + uwu->p_size / 2;
	ra = uwu->pa;
	for (r = 0; r < 1; r++)
	{
		dof = 0;
		float aTan = -1/tan(ra);
		if (ra > PI)
		{
			ry = (((int)py/uwu->m_size)*uwu->m_size)-0.0001;
			rx = (py-ry)*aTan+px;
			yo = -uwu->m_size;
			xo = -yo*aTan;
		}
		if (ra < PI)
		{
			ry = (((int)py/uwu->m_size)*uwu->m_size) + uwu->m_size;
			rx = (py-ry)*aTan+px;
			yo = uwu->m_size;
			xo = -yo*aTan;
		}
		if (ra == 0 || ra == PI)
		{
			ry = py;
			rx = px;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx)/uwu->m_size;
			my = (int)(ry)/uwu->m_size;
			if (mx+my*mapX > 0 && mx < mapX && my < mapY && uwu->map[my][mx] == '1')
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		draw_line(uwu->ray_img, px, py, rx, ry, RED);

		//HAHA

		dof = 0;
		float nTan = -tan(ra);
		if (ra > P2 && ra < P3)
		{
			rx = (((int)px/uwu->m_size)*uwu->m_size)-0.0001;
			ry = (px-rx)*nTan+py;
			xo = -uwu->m_size;
			yo = -xo*nTan;
		}
		if (ra < P2 || ra > P3)
		{
			rx = (((int)px/uwu->m_size)*uwu->m_size) + uwu->m_size;
			ry = (px-rx)*nTan+py;
			xo = uwu->m_size;
			yo = -xo*nTan;
		}
		if (ra == 0 || ra == PI)
		{
			ry = py;
			rx = px;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx)/uwu->m_size;
			my = (int)(ry)/uwu->m_size;
			if (mx+my*mapX > 0 && mx < mapX && my < mapY && uwu->map[my][mx] == '1')
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		draw_line(uwu->ray_img, px, py, rx, ry, GRE);
	}
}
