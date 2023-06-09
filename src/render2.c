/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:16:33 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/06/08 14:12:59 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t	*fill(mlx_t *mlx, int w, int h, uint32_t color)
{
	mlx_image_t	*image;
	int			x;
	int			y;

	x = 0;
	image = mlx_new_image(mlx, w, h);
	while (x < (int)image->width)
	{
		y = 0;
		while (y < (int) image->height)
		{
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
	return (image);
}

void	fill_img(t_cub3d *uwu, int w, int h, uint32_t color)
{
	int	x;
	int	y;

	x = w;
	while (x < w + uwu->m_size)
	{
		y = h;
		while (y < h + uwu->m_size)
		{
			mlx_put_pixel(uwu->map_img, x, y, color);
			y++;
		}
		x++;
	}
}

int	is_transparent(char c)
{
	if (c == '0' || c == '3' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (1);
	return (0);
}
