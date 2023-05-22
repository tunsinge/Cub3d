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

	//int xo = 0; if(uwu->ray->pdx<0){xo=-20;} else{xo=20;}
	//int yo = 0; if(uwu->ray->pdy<0){yo=-20;} else{yo=20;}
	//int	ipx=uwu->px/(float)uwu->m_size, ipx_a=(uwu->px+xo)/uwu->m_size, ipx_s=(uwu->px-xo)/uwu->m_size;
	//int	ipy=uwu->py/(float)uwu->m_size, ipy_a=(uwu->py+yo)/uwu->m_size, ipy_s=(uwu->py-yo)/uwu->m_size;
	if (keydata.key == 'W')
	{
		//if (uwu->map[ipy][ipx_a]=='0'){uwu->px+=uwu->ray->pdx;}
		//if (uwu->map[ipy_a][ipx]=='0'){uwu->py+=uwu->ray->pdy;}
//		if (uwu->map[(int)uwu->py/uwu->m_size][(int)uwu->ray->pxx/uwu->m_size] != '1')
			uwu->px += uwu->ray->pdx;
//		if (uwu->map[(int)uwu->ray->pyy/uwu->m_size][(int)uwu->px/uwu->m_size] != '1')
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
	render(uwu);
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
	uwu->mapX = 8;
	uwu->mapY = 5;
	uwu->map_s_y = ft_strrlen(uwu->map);
	uwu->map_s_x = ft_strlen(uwu->map[0]);
	uwu->ray = malloc(sizeof(t_ray));
	uwu->mlx = mlx_init(windowWidth, windowHeight, "cub3d", true);
	load_textures(uwu->textures);
}

int	main(int ac, char **av)
{
	t_cub3d	*uwu;

	if (ac != 2)
		return ((error(INV_ARGS), 1));
	uwu = malloc(sizeof(t_cub3d));
	init_(uwu, av);
	printf("%d\n", check_map_closed(uwu));
	init_img(uwu);
	render(uwu);
	mlx_key_hook(uwu->mlx, &key_hook, uwu);
	mlx_loop(uwu->mlx);
	mlx_terminate(uwu->mlx);
	delete_textures(uwu->textures);
}
