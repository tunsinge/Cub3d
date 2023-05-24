/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:32 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/24 17:19:55by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	test_collide(t_cub3d *uwu, int x, int y)
{
//	printf("px, py 	: %f, %f\n", uwu->px, uwu->py);
//	printf("mx, my 	: %d, %d\n", uwu->map_s_x, uwu->map_s_y);
//	printf("x, y 	: %d, %d\n", x, y);
	if (x > uwu->map_s_x || y > uwu->map_s_y)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	if (uwu->map[y][x] != '1')
		uwu->map[y][x] = 'P';
//	printf("map[y]    : %s\n", uwu->map[y]);
//	printf("map[x][y] : %c\n", uwu->map[y][x]);
//	print_map(uwu);
//	printf("--------------\n");
	return (uwu->map[y][x] == '1');
}

//todo l'algo des collisions il morche pos

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

void	move_x(t_cub3d *uwu, float dx)
{
	int	i;
	float	nb;

	i = 0;
	nb = 0;
	nb = uwu->px + dx * uwu->speed + 5 * (dx > 0);
	if (uwu->map[(int)uwu->py / uwu->map_s_x][(int)nb / uwu->map_s_x] == '1')
		return ;
	uwu->px += dx * uwu->speed;
}

void	move_y(t_cub3d *uwu, float dy)
{
	int	i;
	float	nb;

	i = 0;
	nb = 0;
	nb = uwu->py + dy * uwu->speed + 5 * (dy > 0);
	if (uwu->map[(int)nb / uwu->map_s_x][(int)uwu->px / uwu->map_s_x] == '1')
		return ;
	uwu->py += dy * uwu->speed;
}
