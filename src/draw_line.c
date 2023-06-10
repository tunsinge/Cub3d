/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:05:31 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/06/08 11:05:31 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_drwlvars
{
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	sx;
	int	sy;
}	t_drwlvars;

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
		if (x0 >= 0 && x0 <= WINW && y0 >= 0 && y0 <= WINH)
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
