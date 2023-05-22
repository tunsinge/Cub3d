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

float dist (float ax, float ay, float bx, float by)
{
	return (sqrt((bx-ax) * (bx-ax) + (by-ay) * (by-ay)));
}

void	check_angle(float *ra)
{
	if (*ra < 0)
		*ra += 2*PI;
	if (*ra>2*PI)
		*ra -= 2*PI;
}

void	raycaster(t_cub3d *uwu)
{
	float	px, py, pa, rx, ry, ra, xo, yo,ray_nb,r,disT;
	int		mx,my,mp,dof;
	int		w = 480 * scale, h = 320 * scale;

	px = uwu->px + uwu->p_size / 2;
	py = uwu->py + uwu->p_size / 2;
	ra = uwu->pa-DR*30;
	pa = uwu->pa;
	check_angle(&ra);
	ray_nb = 480;
	for (r = 0; r < ray_nb; r++)
	{
		dof = 0;
		float disH=1000000, hx=px, hy=py;
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
			{
				hx=rx;
				hy=ry;
				disH=dist(px,py,hx,hy);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}

		//HAHA

		dof = 0;
		float disV=1000000, vx=px, vy=py;
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
			{
				vx=rx;
				vy=ry;
				disV=dist(px,py,vx,vy);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}

		float shade = 1;
		if (disV<disH)
		{
			rx=vx;
			ry=vy;
			disT = disV;
		}
		if (disV>disH)
		{
			shade = 0.5;
			rx=hx;
			ry=hy;
			disT = disH;
		}
		//draw_line(uwu->ray_img, px, py, rx, ry, RED);

		//---Draw 3D Walls---
		float ca=pa-ra;
		disT = disT*cosf(ca);
		check_angle(&ca);
		float lineH=(uwu->m_size*h)/disT;

		float	sext = uwu->textures->text_no->width;
		float	seyt = uwu->textures->text_no->height;

		float ty_step = seyt/(float)lineH;
		float ty_off = 0;
		if(lineH>h){ty_off = (lineH-h)/2.0;lineH=h;}
		float lineO=h/2-lineH/2;

		int y;
		float ty = ty_step*ty_off;
		float tx;

		if (shade != 1){ tx=(int)(rx/(uwu->m_size/sext))%(int)sext;} // if(ra<PI){ tx=31-tx ;} }
		else		   { tx=(int)(ry/(uwu->m_size/sext))%(int)seyt;}// if (ra>P2 && ra<P3) { tx=31-tx; }}

		mlx_texture_t	*texture;
		for (y = 0; y < lineH; y++)
		{
			int color = pixel_to_color(texture, tx, ty);
			for (int z = 0; z < w/ray_nb; z++)mlx_put_pixel(uwu->trwaD_img, r*w/ray_nb+z, lineO+y, color);
			ty += ty_step;
		}

		for (int z = 0; z < w/ray_nb; z++)
		{
			draw_line(uwu->trwaD_img, r*w/ray_nb+z, 0, r*w/ray_nb+z, lineO, CYA); // Plafond
			//draw_line(r*8+530+z, lineO, r*8+530+z, lineH+lineO, color); // Mur
			draw_line(uwu->trwaD_img, r*w/ray_nb+z, lineH+lineO, r*w/ray_nb+z, h - 1, GRE); // Sol
		}

		ra+=DR*(60 / ray_nb);
		check_angle(&ra);
	}
}
