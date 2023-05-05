/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:58:49 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/05 17:01:47by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# define PI 3.1415926535
# define P2 PI/2
# define P3 3*PI/2

void drawRays3D ();
void	draw_line(int x0, int y0, int x1, int y1);

mlx_t	*mlx;
mlx_image_t	*plyr_img;
mlx_image_t	*dir_img;
float	px, py, pdx, pdy, pa;
int	mapX=8, mapY=8, mapS=64;
int	map[]=
{
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,1,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	sign(int n)
{
	if (n < 0)
		return (-1);
	return (n != 0);
}

float dist (float ax, float ay, float bx, float by)
{
	return (sqrt((bx-ax) * (bx-ax) + (by-ay) * (by-ay)) );
}

void drawRays3D ()
{
	int r,mx, my, mp, dof; float rx, ry, ra, xo, yo;
	ra=pa;
	for (r=0;r<1;r++)
	{
		//---Check Horizontal Lines---
		dof=0;
		float disH = 1000000,hx=px,hy=py;
		float aTan=-1/tan(ra);
		if (ra>PI) { ry=(((int) py>>6) <<6) -0.0001;	rx= (py-ry)*aTan+px; yo=-64; xo=-yo*aTan;}
		if (ra<PI) { ry=(((int) py>>6) <<6)+64;			rx= (py-ry)*aTan+px; yo= 64; xo=-yo*aTan;}
		if (ra==0 || ra==PI) { rx=px; ry=py; dof=8; }//looking straight left or right
		while (dof<8)
		{
			mx = (int) (rx) >> 6; my= (int)(ry)>>6; mp=my*mapX+mx;
			if (mp > 0 && mp<mapX*mapY && map[mp]==1){ hx=rx;hy=ry;disH=dist(px,py,hx,hy);dof=8; }//hit wall
			else{ rx+=xo; ry+=yo; dof+=1; }//next line
		}

		//---Check Vertical Lines---
		dof=0;
		float disV = 1000000,vx=px,vy=py;
		float nTan=-tan(ra);
		if (ra>P2 && ra < P3) { rx=(((int) px>>6) <<6) -0.0001; ry= (px-rx) *nTan+py; xo=-64; yo=-xo*nTan;}
		if (ra<P2 || ra > P3) { rx=(((int) px>>6) <<6)+64; ry=(px-rx) *nTan+py; xo= 64; yo=-xo*nTan;}
		if (ra==0 || ra==PI) { rx=px; ry=py; dof=8; }//looking straight left or right
		while (dof<8)
		{
			mx = (int) (rx) >> 6; my= (int)(ry)>>6; mp=my*mapX+mx;
			if (mp > 0 && mp<mapX*mapY && map [mp]==1){vx=rx;vy=ry;disV=dist(px,py,vx,vy); dof=8; }//hit wall
			else{ rx+=xo; ry+=yo; dof+=1; }//next line
		}
		if(disV<disH){rx=vx;ry=vy;}
		if(disV>disH){rx=hx;ry=hy;}
		draw_line(px + 4, py + 4, rx, ry);
	}
}

void	draw_line(int x0, int y0, int x1, int y1)
{
	int dx = ft_abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = ft_abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;

	for(;;)
	{
		if (x0 >= 0 && x0 <= 1024 && y0 >= 0 && y0 <= 512)
			mlx_put_pixel(dir_img, x0, y0, RED);
		else
			return ;
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void	mouse(void *param)
{
	(void)param;
	int	x, y;

	mlx_get_mouse_pos(mlx, &x, &y);
	draw_line(100, 100, x, y);
}

mlx_image_t	*fill(mlx_t *mlx, int w, int h, uint32_t color)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, w, h);
	for (int x = 0; x < (int)image->width; x++)
		for(int y = 0; y < (int)image->height; y++)
			mlx_put_pixel(image, x, y, color);
	return (image);
}

void	drawMap2D()
{
	mlx_image_t *tmp;
	int	x,y,xo,yo,color;

	for (y=0; y < mapY; y++)
	{
		for (x = 0; x < mapX; x++)
		{
			if (map[y*mapX+x] == 0)
				color = BLA;
			else
				color = WHI;
			xo = x*mapS;
			yo = y*mapS;
			tmp = fill(mlx, mapS-1, mapS-1, color);
			mlx_image_to_window(mlx, tmp, xo+1, yo+1);
		}
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	(void)param;

	if (keydata.key == 'A') {pa -= 0.1; if (pa < 0){ pa+=2*PI;} pdx=cos(pa)*5; pdy=sin(pa)*5;}
	if (keydata.key == 'D') {pa += 0.1; if (pa > 2*PI){pa -= 2*PI;} pdx=cos(pa)*5; pdy=sin(pa)*5;}
	if (keydata.key == 'W') {px+=pdx; py+=pdy;}
	if (keydata.key == 'S') {px-=pdx; py-=pdy;}
	if (keydata.key == MLX_KEY_ESCAPE) {exit(0);}

	//Draw direction line
	mlx_delete_image(mlx, dir_img);
	dir_img = mlx_new_image(mlx, 1024, 512);
	drawRays3D();
	mlx_image_to_window(mlx, dir_img, 0, 0);
}

void	draw_player(void *param)
{
	(void)param;

	mlx_delete_image(mlx, plyr_img);
	plyr_img = fill(mlx, 8, 8, YEL);
	mlx_image_to_window(mlx, plyr_img, px, py);

}

void	display()
{
	//draw_player();
	drawMap2D();
}

void	init()
{
	px = 300;
	py = 300;
	dir_img = mlx_new_image(mlx, 1024, 512);
	//pdx = cos(pa) * 5;
	//pdy = sin(pa) * 5;
}

int	main()
{
	mlx = mlx_init(1024, 512, "cub3d", true);
	init();
	display();

	//mlx_loop_hook(mlx, &mouse, NULL);
	mlx_loop_hook(mlx, &draw_player, NULL);
	mlx_key_hook(mlx, &key_hook, NULL);
	mlx_loop(mlx);
}
