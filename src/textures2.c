/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:54:19 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/06/10 08:54:20 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_size(t_cub3d *uwu)
{
	uwu->ray->sext = uwu->ray->t->width;
	uwu->ray->seyt = uwu->ray->t->height;
}

void	pick_textures(t_cub3d *uwu, int egal, int type)
{
	if (type == 1)
	{
		if (uwu->ray->is_door[1] == 2)
			uwu->ray->t = uwu->ricks[0]->current;
		else if (uwu->ray->is_door[1] == 1 && egal)
			uwu->ray->t = uwu->t->door_we;
		else if (uwu->ray->is_door[1] == 1)
			uwu->ray->t = uwu->t->door_ea;
		else if (egal)
			uwu->ray->t = uwu->t->text_we;
		else
			uwu->ray->t = uwu->t->text_ea;
	}
	else
		pick_textures2(uwu, egal);
	set_texture_size(uwu);
}

void	pick_textures2(t_cub3d *uwu, int egal)
{
	if (uwu->ray->is_door[0] == 2)
		uwu->ray->t = uwu->ricks[1]->current;
	else if (uwu->ray->is_door[0] == 1 && egal)
		uwu->ray->t = uwu->t->door_no;
	else if (uwu->ray->is_door[0] == 1)
		uwu->ray->t = uwu->t->door_so;
	else if (egal)
		uwu->ray->t = uwu->t->text_no;
	else
		uwu->ray->t = uwu->t->text_so;
}
