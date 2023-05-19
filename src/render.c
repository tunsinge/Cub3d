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

void	render_player(t_cub3d *uwu)
{
	uwu->player_img->instances[0].x = uwu->px;
	uwu->player_img->instances[0].y = uwu->py;

	uwu->ray->pxx = uwu->ray->pdx*5 + uwu->px;
	uwu->ray->pyy = uwu->ray->pdy*5 + uwu->py;

	//ft_bzero(uwu->ray_img, sizeof(uwu->ray_img));
	mlx_delete_image(uwu->mlx, uwu->ray_img);
	uwu->ray_img = mlx_new_image(uwu->mlx, windowWidth, windowHeight);
	//draw_line(uwu->ray_img, uwu->px+uwu->p_size/2, uwu->py+uwu->p_size/2, uwu->ray->pxx+uwu->p_size/2, uwu->ray->pyy+uwu->p_size/2, RED);
	mlx_image_to_window(uwu->mlx, uwu->ray_img, 0, 0);
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

	render_player(uwu);
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

void	render_map(t_cub3d *uwu)
{
	int	i;
	int	j;
	mlx_image_t	*tmp;

	i = 0;
	while (uwu->map[i])
	{
		j = 0;
		while (uwu->map[i][j])
		{
			tmp = color_chart(uwu, uwu->map[i][j]);
			mlx_image_to_window(uwu->mlx, tmp, j*uwu->m_size, i*uwu->m_size);
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
