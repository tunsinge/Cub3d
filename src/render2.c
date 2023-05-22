/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:16:33 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/22 19:16:36 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_cub3d *uwu)
{
	int	i;
	int	j;

	uwu->map_img = mlx_new_image(uwu->mlx, uwu->map_s_x * (uwu->m_size + 1),
			uwu->map_s_y * (uwu->m_size + 1));
	i = 0;
	while (uwu->map[i])
	{
		j = 0;
		while (uwu->map[i][j])
		{
			if (uwu->map[i][j] == '1')
				fill_img(uwu->map_img, j * uwu->m_size, i * uwu->m_size, BLA,
					uwu->m_size);
			if (!is_etranger(uwu->map[i][j]) && uwu->map[i][j] != '1')
				fill_img(uwu->map_img, j * uwu->m_size, i * uwu->m_size, WHI,
					uwu->m_size);
			j++;
		}
		i++;
	}
	mlx_image_to_window(uwu->mlx, uwu->map_img, 0, 0);
	uwu->map_img->instances[0].z = 1;
}

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

void	fill_img(mlx_image_t *img, int w, int h, uint32_t color, int size)
{
	int	x;
	int	y;

	x = w;
	while (x < w + size)
	{
		y = h;
		while (y < h + size)
		{
			mlx_put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}
