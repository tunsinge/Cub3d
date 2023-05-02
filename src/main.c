/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:57:56 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/02 16:49:36 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(char **av)
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

int	main(int ac, char **av)
{
	if (ac != 2)
		return ((printf("Error\nArguments are not valid.\n"), 0));
	check_map(av);

	map_to_tab("./map.cub");

	//mlx_t	*mlx;

	//mlx = mlx_init(1080, 720, "cub3d", true);
	//mlx_image_t	*image_wall;
	//mlx_image_t	*image_ground;

	//image_wall = fill(mlx, 64, 64, 0xFFFFFFFF);
	//image_ground = fill(mlx, 64, 64, 0xFFFF00FF);

	//mlx_image_to_window(mlx, image_wall, 0, 0);
	//mlx_image_to_window(mlx, image_ground, 64, 64);

	//mlx_loop(mlx);
}
