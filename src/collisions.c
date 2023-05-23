/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:32 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/23 14:47:33 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	test_collide(t_cub3d *uwu, int x, int y)
{
	printf("px, py 	: %f, %f\n", uwu->px, uwu->py);
	printf("mx, my 	: %d, %d\n", uwu->map_s_x, uwu->map_s_y);
	printf("x, y 	: %d, %d\n", x, y);
	if (x > uwu->map_s_x || y > uwu->map_s_y)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	if (uwu->map[y][x] != '1')
		uwu->map[y][x] = 'P';
	printf("map[y]    : %s\n", uwu->map[y]);
	printf("map[x][y] : %c\n", uwu->map[y][x]);
	print_map(uwu);
	printf("--------------\n");
	return (uwu->map[y][x] == '1');
}

int	find_x_pos(t_cub3d *uwu, int dx)
{
	int	px;
	int	x;

	px = uwu->px + (dx * uwu->speed);
	x = px / uwu->map_s_x;
	return (x);
}

int	find_y_pos(t_cub3d *uwu, int dy)
{
	int	py;
	int	y;

	py = uwu->py + (dy * uwu->speed);
	y = py / uwu->map_s_y;
	return (y);
}

void	move_x(t_cub3d *uwu, int dx)
{
	if (!test_collide(uwu, find_x_pos(uwu, dx), find_y_pos(uwu, 0)))
		uwu->px += dx * uwu->speed;
}

void	move_y(t_cub3d *uwu, int dy)
{
	if (!test_collide(uwu, find_x_pos(uwu, 0), find_y_pos(uwu, dy)))
		uwu->py += dy * uwu->speed;
}
