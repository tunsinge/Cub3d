/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:46:38 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/06/01 16:46:39 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rick_load_texture(t_cub3d *uwu)
{
	int	xy[2];
	int	wh[2];

	uwu->t->current_x = 0;
	uwu->t->rick_full = mlx_load_png("textures/texture.png");
	xy[0] = uwu->t->current_x;
	xy[1] = 0;
	wh[0] = 498;
	wh[1] = 427;
	uwu->t->rick_current = texture_area_to_texture(uwu->t->rick_full, xy, wh);
}

void	rick_next(t_cub3d *uwu)
{
	static int	i = 0;
	int			xy[2];
	int			wh[2];

	i++;
	if (i < 3)
		return ;
	i = 0;
	uwu->t->current_x += 498;
	if (uwu->t->current_x > uwu->t->rick_full->width)
		uwu->t->current_x = 0;
	mlx_delete_texture(uwu->t->rick_current);
	xy[0] = uwu->t->current_x;
	xy[1] = 0;
	wh[0] = 498;
	wh[1] = 427;
	uwu->t->rick_current = texture_area_to_texture(uwu->t->rick_full, xy, wh);
}

void	set_texture_size(t_cub3d *uwu)
{
	uwu->ray->sext = uwu->ray->t->width;
	uwu->ray->seyt = uwu->ray->t->height;
}
