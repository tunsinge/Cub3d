/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:16:49 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/18 01:40:54 by mdoumi           ###   ########.fr       */
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
	uwu->ray->pxx = uwu->ray->pdx * 5 + uwu->px;
	uwu->ray->pyy = uwu->ray->pdy * 5 + uwu->py;
}

void	init_player(t_cub3d *uwu)
{
	uwu->px = uwu->px * uwu->m_size + uwu->m_size * 3 / 8;
	uwu->py = uwu->py * uwu->m_size + uwu->m_size * 3 / 8;
	uwu->ray->pdx = cosf(uwu->pa) * 5;
	uwu->ray->pdy = sinf(uwu->pa) * 5;
	uwu->ray->pxx = uwu->ray->pdx * 5 + uwu->px;
	uwu->ray->pyy = uwu->ray->pdy * 5 + uwu->py;
	uwu->player_img = fill(uwu->mlx, uwu->p_size, uwu->p_size, uwu->p_color);
	mlx_image_to_window(uwu->mlx, uwu->player_img, uwu->px, uwu->py);
	uwu->player_img->instances[0].z = 2;
}
