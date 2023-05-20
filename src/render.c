/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:16:49 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/18 01:40:54by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	if (n == 0)
		return ;
	i = 0;
	temp = (char *)s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

void	init_img(t_cub3d *uwu)
{
	init_player(uwu);
	init_map(uwu);
	uwu->trwaD_img = mlx_new_image(uwu->mlx, windowWidth, windowHeight);

	raycaster(uwu);

	mlx_image_to_window(uwu->mlx, uwu->trwaD_img, 0, 0);
	uwu->trwaD_img->instances[0].z = 0;
}

void	render(t_cub3d *uwu)
{
	render_player(uwu);

	raycaster(uwu);
}

void	render_player(t_cub3d *uwu)
{
	uwu->player_img->instances[0].x = uwu->px;
	uwu->player_img->instances[0].y = uwu->py;

	uwu->ray->pxx = uwu->ray->pdx*5 + uwu->px;
	uwu->ray->pyy = uwu->ray->pdy*5 + uwu->py;
}

void	init_player(t_cub3d *uwu)
{
	uwu->px = uwu->px * uwu->m_size + uwu->m_size * 3/8;
	uwu->py = uwu->py * uwu->m_size + uwu->m_size * 3/8;

	uwu->ray->pdx = cosf(uwu->pa) * 5;
	uwu->ray->pdy = sinf(uwu->pa) * 5;

	uwu->ray->pxx = uwu->ray->pdx*5 + uwu->px;
	uwu->ray->pyy = uwu->ray->pdy*5 + uwu->py;

	uwu->player_img = fill(uwu->mlx, uwu->p_size, uwu->p_size, uwu->p_color);
	mlx_image_to_window(uwu->mlx, uwu->player_img, uwu->px, uwu->py);
	uwu->player_img->instances[0].z = 2;
}

mlx_image_t	*color_chart(t_cub3d *uwu, char value)
{
	int	size;

	size = uwu->m_size;
	if (value == '1')
		return (fill(uwu->mlx, size, size, BLA));
	if (value == '0')
		return (fill(uwu->mlx, size, size, WHI));
	if (value == 'N')
		return (fill(uwu->mlx, size, size, WHI));
	if (value == 'S')
		return (fill(uwu->mlx, size, size, WHI));
	if (value == 'E')
		return (fill(uwu->mlx, size, size, WHI));
	if (value == 'W')
		return (fill(uwu->mlx, size, size, WHI));
	return (NULL);
}

void	init_map(t_cub3d *uwu)
{
	int	i;
	int	j;
	uwu->map_img = mlx_new_image(uwu->mlx, uwu->mapX*(uwu->m_size+1), uwu->mapY*(uwu->m_size+1));

	i = 0;
	while (uwu->map[i])
	{
		j = 0;
		while (uwu->map[i][j])
		{
			if (uwu->map[i][j] == '1')
				fill_img(uwu->map_img, j*uwu->m_size, i*uwu->m_size, BLA, uwu->m_size);
			if (!is_etranger(uwu->map[i][j]) && uwu->map[i][j] != '1')
				fill_img(uwu->map_img, j*uwu->m_size, i*uwu->m_size, WHI, uwu->m_size);
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

	image = mlx_new_image(mlx, w, h);
	for (int x = 0; x < (int)image->width; x++)
		for(int y = 0; y < (int)image->height; y++)
			mlx_put_pixel(image, x, y, color);
	return (image);
}

void	fill_img(mlx_image_t *img, int w, int h, uint32_t color, int size)
{
	for (int x = w; x < w+size; x++)
		for(int y = h; y < h+size; y++)
			mlx_put_pixel(img, x, y, color);
}

