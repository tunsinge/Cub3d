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

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*uwu;

	uwu = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
		quit_program();
	if (keydata.key == 'W')
		uwu->player_img->instances[0].y -= 5;
	if (keydata.key == 'S')
		uwu->player_img->instances[0].y += 5;
	if (keydata.key == 'A')
		uwu->player_img->instances[0].x -= 5;
	if (keydata.key == 'D')
		uwu->player_img->instances[0].x += 5;
}


void	init_(t_cub3d *uwu, char **av)
{
	check_map_path(av);

	uwu->map = parse_map(uwu, av[1]);
	check_map(uwu->map);

	uwu->tab = tab_to_struct(uwu);
	uwu->case_size = 64;
	get_pp(uwu);
	uwu->mlx = mlx_init(1080, 720, "cub3d", true);
	uwu->player_size = uwu->case_size / 4;
	uwu->player_img = fill(uwu->mlx, uwu->player_size, uwu->player_size, BLA);
}

int	main(int ac, char **av)
{
	t_cub3d	*uwu;

	if (ac != 2)
		return ((error(INV_ARGS), 1));

	uwu = malloc(sizeof(t_cub3d));
	init_(uwu, av);

	render(uwu);
	render_player(uwu);
	mlx_key_hook(uwu->mlx, &key_hook, uwu);
	mlx_loop(uwu->mlx);
}
