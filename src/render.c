/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:16:49 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/04 12:17:37 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_player(t_cub3d *uwu)
{
	mlx_image_to_window(uwu->mlx, uwu->player_img, uwu->p_x * uwu->case_size + uwu->case_size * 3/8, uwu->p_y * uwu->case_size + uwu->case_size * 3/8);
}

mlx_image_t	*color_chart(t_cub3d *uwu, char value)
{
	int	size;

	size = uwu->case_size;
	if (value == '1')
		return (fill(uwu->mlx, size, size, BLA));
	if (value == '0')
		return (fill(uwu->mlx, size, size, WHI));
	if (value == 'N')
		return (fill(uwu->mlx, size, size, BLU));
	if (value == 'S')
		return (fill(uwu->mlx, size, size, GRE));
	if (value == 'E')
		return (fill(uwu->mlx, size, size, RED));
	if (value == 'W')
		return (fill(uwu->mlx, size, size, PIN));
	return (NULL);
}

void	render(t_cub3d *uwu)
{
	int	i;
	int	j;

	i = 0;
	while (uwu->tab[i])
	{
		j = 0;
		while (uwu->tab[i][j])
		{
			uwu->tab[i][j]->img = color_chart(uwu, uwu->tab[i][j]->value);
			mlx_image_to_window(uwu->mlx, uwu->tab[i][j]->img, j*uwu->case_size, i*uwu->case_size);
			j++;
		}
		i++;
	}
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
