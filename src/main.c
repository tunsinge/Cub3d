/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:57:56 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/24 19:00:51 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_(t_cub3d *uwu, char **av)
{
	uwu->textures = malloc(sizeof(t_textures));
	uwu->textures->texture_no = NULL;
	uwu->textures->texture_so = NULL;
	uwu->textures->texture_we = NULL;
	uwu->textures->texture_ea = NULL;
	uwu->textures->color_fl = 0;
	uwu->textures->color_ce = 0;
	uwu->speed = 0;
	uwu->hehe = 0;
	uwu->jumping = 0;
	if (check_map_path(av))
		quit_program();
	uwu->map = parse_map(uwu, av[1]);
	if (!uwu->map)
		quit_program();
	if (check_map(uwu->map))
		quit_program();
	fill_map(uwu);
	uwu->p_color = CYA;
	if (get_pp(uwu))
		quit_program();
	uwu->map_s_y = ft_strrlen(uwu->map);
	uwu->map_s_x = ft_strlen(uwu->map[0]);
	uwu->m_size = 256 / uwu->map_s_x;
	uwu->p_size = uwu->m_size / 4;
	printf("map_s_x : %d, map_s_y : %d\n", uwu->map_s_x, uwu->map_s_y);
	uwu->ray = malloc(sizeof(t_ray));
	uwu->mlx = mlx_init(windowWidth, windowHeight, "cub3d", true);
	if (load_textures(uwu->textures))
		return (quit_program());
	mlx_set_cursor_mode(uwu->mlx, MLX_MOUSE_HIDDEN);
}

int	main(int ac, char **av)
{
	t_cub3d	*uwu;

	if (ac != 2)
		return ((error(INV_ARGS), 1));
	uwu = malloc(sizeof(t_cub3d));
	init_(uwu, av);
	init_img(uwu);
	init_controls(uwu);
	mlx_key_hook(uwu->mlx, &key_hook, uwu);
	mlx_loop_hook(uwu->mlx, &controls_hook, uwu);
	render(uwu);
	mlx_loop(uwu->mlx);
	delete_textures(uwu->textures);
	mlx_terminate(uwu->mlx);
}
