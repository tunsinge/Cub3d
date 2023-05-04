/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:57:56 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/04 10:05:25 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_path(char **av)
{
	char *s;

	s = ft_substr(av[1], ft_strlen(av[1]) - 4, ft_strlen(av[1]));
	if (ft_strcmp(s, ".cub") != 0)
		printf("Error\nMap is not valid. It must end with .cub.\n");
	free(s);
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

void	key_hook(mlx_key_data_t keydata, void *param)
{
	(void)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
		quit_program();
}

int	main(int ac, char **av)
{
	t_cub3d	*uwu;

	if (ac != 2)
		return ((error(INV_ARGS), 1));
	check_map_path(av);

	uwu = malloc(sizeof(t_cub3d));
	//Parser le debut
	uwu->map = map_to_tab(av[1]);
	check_map(uwu->map);

	uwu->mlx = mlx_init(1080, 720, "cub3d", true);
	mlx_key_hook(uwu->mlx, &key_hook, NULL);
	mlx_loop(uwu->mlx);
}
