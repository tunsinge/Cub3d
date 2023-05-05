/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:58:49 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/05 08:48:00 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# define PI 3.1415926535

mlx_t	*mlx;
mlx_image_t	*plyr_img;
float	p_x, p_y, pdx, pdy, pa;
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

void	draw_line(int x1, int y1, int x2, int y2)
{
	int	x = 0, y = 0;
	float	error = 0;
	float	slope = (y2 - y1) / (x2 - x1);
	mlx_image_t *line_img;

	line_img = mlx_new_image(mlx, x2-x1, y2-y1);
	//mlx_put_pixel(line_img, 0, 0, YEL);
	for (x = 0; x < x2-x1; x++)
	{
		error = error + slope;
		if (error >= 0.5)
		{
			y++;
			error--;
		}
		mlx_put_pixel(line_img, x, y, YEL);
	}
	mlx_image_to_window(mlx, line_img, x1, y1);

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

	//if (keydata.key == 'A') {pa -= 0.1; if (pa < 0){ pa+=2*PI;} pdx=cos(pa)*5; pdy=sin(pa)*5;}
	//if (keydata.key == 'D') {pa += 0.1; if (pa > 2*PI){pa -= 2*PI;} pdx=cos(pa)*5; pdy=sin(pa)*5;}
	//if (keydata.key == 'W') {p_x+=pdx; p_y+=pdy;}
	//if (keydata.key == 'S') {p_x-=pdx; p_y-=pdy;}
}

void	draw_player(void *param)
{
	(void)param;

	mlx_delete_image(mlx, plyr_img);
	plyr_img = fill(mlx, 8, 8, YEL);
	mlx_image_to_window(mlx, plyr_img, p_x, p_y);

	//Draw direction line
}

void	display()
{
	//draw_player();
	drawMap2D();
}

void	init()
{
	p_x = 300;
	p_y = 300;
	//pdx = cos(pa) * 5;
	//pdy = sin(pa) * 5;
}

int	main()
{
	init();
	mlx = mlx_init(1024, 512, "cub3d", true);
	//display();
	draw_line(100, 100, 150, 150);

	//mlx_loop_hook(mlx, &draw_player, NULL);
	mlx_key_hook(mlx, &key_hook, NULL);
	mlx_loop(mlx);
}
