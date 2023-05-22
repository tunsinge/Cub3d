/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_v.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:32:02 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/22 19:32:03 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical(t_cub3d *uwu)
{
	VAR->dof = 0;
	VAR->dis_v = 1000000;
	VAR->vx = VAR->px;
	VAR->vy = VAR->py;
	VAR->ntan = -tan(VAR->ra);
	if (VAR->ra > P2 && VAR->ra < P3)
	{
		VAR->rx = (((int)VAR->px / uwu->m_size) * uwu->m_size) - 0.0001;
		VAR->ry = (VAR->px - VAR->rx) * VAR->ntan + VAR->py;
		VAR->xo = -uwu->m_size;
		VAR->yo = -VAR->xo * VAR->ntan;
	}
	if (VAR->ra < P2 || VAR->ra > P3)
	{
		VAR->rx = (((int)VAR->px / uwu->m_size) * uwu->m_size)
			+ uwu->m_size;
		VAR->ry = (VAR->px - VAR->rx) * VAR->ntan + VAR->py;
		VAR->xo = uwu->m_size;
		VAR->yo = -VAR->xo * VAR->ntan;
	}
	if (VAR->ra == 0 || VAR->ra == PI)
	{
		VAR->ry = VAR->py;
		VAR->rx = VAR->px;
		VAR->dof = 50;
	}
	while (VAR->dof < 50)
	{
		VAR->mx = (int)(VAR->rx) / uwu->m_size;
		VAR->my = (int)(VAR->ry) / uwu->m_size;
		if (VAR->mx + VAR->my * uwu->map_s_x > 0 && VAR->mx < uwu->map_s_x
			&& VAR->my < uwu->map_s_y
			&& uwu->map[VAR->my][VAR->mx] == '1')
		{
			VAR->vx = VAR->rx;
			VAR->vy = VAR->ry;
			VAR->dis_v = dist(VAR->px, VAR->py, VAR->vx, VAR->vy);
			VAR->dof = 50;
		}
		else
		{
			VAR->rx += VAR->xo;
			VAR->ry += VAR->yo;
			VAR->dof++;
		}
	}
}
