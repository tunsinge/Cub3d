/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:16:49 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/26 12:06:05 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_cub3d *uwu)
{
	init_player(uwu);
	init_map(uwu);
	uwu->trwad_img = mlx_new_image(uwu->mlx, WINW, WINH + 200);
	raycaster(uwu);
	mlx_image_to_window(uwu->mlx, uwu->trwad_img, 0, 0);
	uwu->trwad_img->instances[0].z = 0;
}

void	render(t_cub3d *uwu)
{
	render_player(uwu);
	raycaster(uwu);
}

void	render_player(t_cub3d *uwu)
{
	uwu->player_img->instances[0].x = uwu->px * uwu->m_size / uwu->map_s_x;
	uwu->player_img->instances[0].y = uwu->py * uwu->m_size / uwu->map_s_x;
	uwu->ray->pxx = uwu->ray->pdx * 5 + uwu->px;
	uwu->ray->pyy = uwu->ray->pdy * 5 + uwu->py;
}

void	init_player(t_cub3d *uwu)
{
	uwu->px = uwu->px * uwu->map_s_x + uwu->map_s_x * 3 / 8;
	uwu->py = uwu->py * uwu->map_s_x + uwu->map_s_x * 3 / 8;
	uwu->ray->pdx = cosf(uwu->pa) * 5;
	uwu->ray->pdy = sinf(uwu->pa) * 5;
	uwu->ray->pdxs = cosf(uwu->pa + P2) * 5;
	uwu->ray->pdys = sinf(uwu->pa + P2) * 5;
	uwu->ray->pxx = uwu->ray->pdx * 5 + uwu->px;
	uwu->ray->pyy = uwu->ray->pdy * 5 + uwu->py;
	if (uwu->p_size < 2)
		uwu->p_size = 2;
	uwu->player_img = fill(uwu->mlx, uwu->p_size, uwu->p_size, uwu->p_color);
	mlx_image_to_window(uwu->mlx, uwu->player_img, uwu->px, uwu->py);
	uwu->player_img->instances[0].z = 2;
}

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
				fill_img(uwu, j * uwu->m_size, i * uwu->m_size, BLA);
			if (!is_etranger(uwu->map[i][j]) && uwu->map[i][j] != '1')
				fill_img(uwu, j * uwu->m_size, i * uwu->m_size, WHITR);
			j++;
		}
		i++;
	}
	mlx_image_to_window(uwu->mlx, uwu->map_img, 0, 0);
	uwu->map_img->instances[0].z = 1;
}
