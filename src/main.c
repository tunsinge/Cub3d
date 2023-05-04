/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:57:56 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/04 10:51:32 by mdoumi           ###   ########.fr       */
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

t_case	***tab_to_struct(t_cub3d *uwu)
{
	int		i;
	int		j;
	t_case	***tab;

	i = 0;
	tab = malloc(sizeof(t_case **) * (ft_strrlen(uwu->map) + 2));
	while (uwu->map[i])
	{
		j = 0;
		tab[i] = malloc(sizeof(t_case *) * (ft_strlen(uwu->map[i]) + 1));
		while (uwu->map[i][j])
		{
			tab[i][j] = malloc(sizeof(t_case));
			tab[i][j]->value = uwu->map[i][j];
			j++;
		}
		tab[i][j] = NULL;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	init_(t_cub3d *uwu, char **av)
{
	check_map_path(av);

	uwu->map = map_to_tab(av[1]);
	check_map(uwu->map);

	uwu->tab = tab_to_struct(uwu);
	uwu->mlx = mlx_init(1080, 720, "cub3d", true);
}

void	render(t_cub3d *uwu)
{
	int	i;
	int	j;

	i = 0;
	while (uwu->tab[i])
	{
		j = 0;
		while (uwu->tab[i][j])
		{
			if (uwu->tab[i][j]->value == '1')
				uwu->tab[i][j]->img = fill(uwu->mlx, 60, 60, RED);
			else
				uwu->tab[i][j]->img = fill(uwu->mlx, 60, 60, WHI);
			mlx_image_to_window(uwu->mlx, uwu->tab[i][j]->img, j*64, i*64);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_cub3d	*uwu;

	if (ac != 2)
		return ((error(INV_ARGS), 1));

	uwu = malloc(sizeof(t_cub3d));
	init_(uwu, av);

	render(uwu);

	mlx_key_hook(uwu->mlx, &key_hook, NULL);
	mlx_loop(uwu->mlx);
}
