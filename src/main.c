/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:57:56 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/04 12:07:30by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	roundc(float n)
{
	if (n - (int)n > 0.5)
		return ((int)n + 1);
	return ((int)n);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*uwu;

	uwu = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		quit_program();
	if (keydata.key == 'W')
	{
		//if (uwu->map[roundc(uwu->ray->pyy/uwu->m_size)][roundc(uwu->ray->pxx/uwu->m_size)] != '1')
		//{
			//uwu->px += uwu->ray->pdx;
			//uwu->py += uwu->ray->pdy;
		//}
			uwu->px += uwu->ray->pdx;
			uwu->py += uwu->ray->pdy;
	}
	if (keydata.key == 'S')
	{
		uwu->px -= uwu->ray->pdx;
		uwu->py -= uwu->ray->pdy;
	}
	if (keydata.key == 'A')
	{
		uwu->pa -= 0.1;
		if (uwu->pa < 0)
		{
			uwu->pa += 2*PI;
		}
		uwu->ray->pdx = cosf(uwu->pa)*5;
		uwu->ray->pdy = sinf(uwu->pa)*5;
	}
	if (keydata.key == 'D')
	{
		uwu->pa += 0.1;
		if (uwu->pa > 2*PI)
		{
			uwu->pa -= 2*PI;
		}
		uwu->ray->pdx = cosf(uwu->pa)*5;
		uwu->ray->pdy = sinf(uwu->pa)*5;
	}
	render_player(uwu);
	raycaster(uwu);
}


void	init_(t_cub3d *uwu, char **av)
{
	uwu->textures = malloc(sizeof(t_textures));
	uwu->textures->texture_no = NULL;
	uwu->textures->texture_so = NULL;
	uwu->textures->texture_we = NULL;
	uwu->textures->texture_ea = NULL;
	uwu->textures->color_fl = 0;
	uwu->textures->color_ce = 0;
	check_map_path(av);
	uwu->map = parse_map(uwu, av[1]);
	check_map(uwu->map);
	uwu->m_size = 256 / ft_strlen(uwu->map[0]);
	uwu->p_size = uwu->m_size / 4;
	uwu->p_color = CYA;
	get_pp(uwu);

	uwu->ray = malloc(sizeof(t_ray));
	printf("%f\n", uwu->pa);

	uwu->mlx = mlx_init(windowWidth, windowHeight, "cub3d", true);
}

int	main(int ac, char **av)
{
	t_cub3d	*uwu;

	if (ac != 2)
		return ((error(INV_ARGS), 1));

	uwu = malloc(sizeof(t_cub3d));
	init_(uwu, av);


	render_map(uwu);
	init_player(uwu);
	raycaster(uwu);

	mlx_key_hook(uwu->mlx, &key_hook, uwu);
	mlx_loop(uwu->mlx);
}
