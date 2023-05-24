/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:28:46 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/22 19:28:48 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal(t_cub3d *uwu)
{
	VAR->dof = 0;
	VAR->hx = VAR->px;
	VAR->hy = VAR->py;
	VAR->a_tan = -1 / tan(VAR->ra);
	if (VAR->ra > PI)
	{
		VAR->ry = (((int)VAR->py / uwu->map_s_x) * uwu->map_s_x) - 0.0001;
		VAR->rx = (VAR->py - VAR->ry) * VAR->a_tan + VAR->px;
		VAR->yo = -uwu->map_s_x;
		VAR->xo = -VAR->yo * VAR->a_tan;
	}
	if (VAR->ra < PI)
	{
		VAR->ry = (((int)VAR->py / uwu->map_s_x) * uwu->map_s_x) + uwu->map_s_x;
		VAR->rx = (VAR->py - VAR->ry) * VAR->a_tan + VAR->px;
		VAR->yo = uwu->map_s_x;
		VAR->xo = -VAR->yo * VAR->a_tan;
	}
	if (VAR->ra == 0 || VAR->ra == PI)
	{
		VAR->ry = VAR->py;
		VAR->rx = VAR->px;
		VAR->dof = MAX_DOF;
	}
	horizontal2(uwu);
}

void	horizontal2(t_cub3d *uwu)
{
	while (VAR->dof < MAX_DOF)
	{
		VAR->mx = (int)(VAR->rx) / uwu->map_s_x;
		VAR->my = (int)(VAR->ry) / uwu->map_s_x;
		if (VAR->mx + VAR->my * uwu->map_s_x > 0 && VAR->mx < uwu->map_s_x
			&& VAR->my < uwu->map_s_y
			&& uwu->map[VAR->my][VAR->mx] == '1')
		{
			VAR->hx = VAR->rx;
			VAR->hy = VAR->ry;
			VAR->dis_h = dist(VAR->px, VAR->py, VAR->hx, VAR->hy);
			VAR->dof = MAX_DOF;
		}
		else
		{
			VAR->rx += VAR->xo;
			VAR->ry += VAR->yo;
			VAR->dis_h = 1000000;
			VAR->dof++;
		}
	}
}
