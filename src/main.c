/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:41:06 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/30 13:45:59 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	first_init(t_cub3d *uwu)
{
	uwu->t = malloc(sizeof(t_textures));
	uwu->t->t_no = NULL;
	uwu->t->t_so = NULL;
	uwu->t->t_we = NULL;
	uwu->t->t_ea = NULL;
	uwu->t->text_no = NULL;
	uwu->t->text_so = NULL;
	uwu->t->text_we = NULL;
	uwu->t->text_ea = NULL;
	uwu->ray = malloc(sizeof(t_ray));
	uwu->map = NULL;
	uwu->t->fl = 0;
	uwu->t->ce = 0;
	uwu->speed = N_SPEED;
	uwu->hehe = 0;
	uwu->jumping = 0;
	uwu->mlx = NULL;
}

void	init_(t_cub3d *uwu, char **av)
{
	first_init(uwu);
	if (check_map_path(av))
		quit_program(uwu);
	uwu->map = parse_map(uwu, av[1]);
	if (!uwu->map || !uwu->map[0])
		(error(INVALID_LINE), quit_program(uwu));
	uwu->map_s_y = ft_strrlen(uwu->map);
	uwu->map_s_x = 32;
	uwu->m_size = 256 / find_map_width(uwu);
	uwu->m_fix_size = uwu->m_size;
	uwu->p_size = 8;
	if (!uwu->map)
		quit_program(uwu);
	if (check_map(uwu->map) || !check_map_closed(uwu))
		quit_program(uwu);
	fill_map(uwu);
	uwu->p_color = CYA;
	if (get_pp(uwu))
		quit_program(uwu);
	uwu->mlx = mlx_init(WINW, WINH, "cub3d", true);
	if (load_textures(uwu->t))
		return (quit_program(uwu));
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
	quit_program(uwu);
}
