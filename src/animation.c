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

void	rick_init(t_cub3d *uwu)
{
	uwu->rick_nb = 2;
	uwu->ricks[0] = rick_load_texture("textures/texture.png", 498, 427);
	uwu->ricks[1] = rick_load_texture("textures/texture2.png", 480, 360);
}

t_rick	*rick_load_texture(char *path, int width, int height)
{
	t_rick	*rick;
	int		xy[2];

	rick = malloc(sizeof(t_rick));
	rick->f_nb = 0;
	rick->f_width = width;
	rick->f_height = height;
	rick->f_wh[0] = width;
	rick->f_wh[1] = height;
	rick->full = mlx_load_png(path);
	xy[0] = 0;
	xy[1] = 0;
	rick->current = texture_area_to_texture(rick->full, xy, rick->f_wh);
	return (rick);
}

void	rick_next(t_cub3d *uwu)
{
	static int	i = 0;
	int			j;
	int			xy[2];
	t_rick		*cu_rick;

	i++;
	if (i < 3)
		return ;
	i = 0;
	j = 0;
	while (j < uwu->rick_nb)
	{
		cu_rick = uwu->ricks[j];
		cu_rick->f_nb += cu_rick->f_width;
		if (cu_rick->f_nb > cu_rick->full->width)
			cu_rick->f_nb = 0;
		mlx_delete_texture(cu_rick->current);
		xy[0] = cu_rick->f_nb;
		xy[1] = 0;
		cu_rick->current = texture_area_to_texture(cu_rick->full,
				xy, cu_rick->f_wh);
		j++;
	}
}

void	rick_delete(t_cub3d *uwu)
{
	int		i;
	t_rick	*cu_rick;

	i = 0;
	while (i < uwu->rick_nb)
	{
		cu_rick = uwu->ricks[i];
		if (cu_rick && cu_rick->full)
			mlx_delete_texture(cu_rick->full);
		if (cu_rick && cu_rick->current)
			mlx_delete_texture(cu_rick->current);
		if (cu_rick)
			free(cu_rick);
		i++;
	}
}
