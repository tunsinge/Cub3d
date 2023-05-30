/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_v.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:32:02 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/26 12:02:32 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical(t_cub3d *uwu)
{
	t_ray	*n;

	((void)0, n = uwu->ray, n->dof = 0, n->vx = n->px, n->vy = n->py);
	n->ntan = -tan(n->ra);
	if (n->ra > P2 && n->ra < P3)
	{
		n->rx = (((int)n->px / 32) * 32) - 0.0001;
		n->ry = (n->px - n->rx) * n->ntan + n->py;
		n->xo = -32;
		n->yo = -n->xo * n->ntan;
	}
	else if (n->ra < P2 || n->ra > P3)
	{
		n->rx = (((int)n->px / 32) * 32) + 32;
		n->ry = (n->px - n->rx) * n->ntan + n->py;
		n->xo = 32;
		n->yo = -n->xo * n->ntan;
	}
	else
	{
		n->ry = n->py;
		n->rx = n->px;
		n->dof = MAX_DOF;
	}
	vertical2(uwu);
}

void	vertical2(t_cub3d *uwu)
{
	t_ray	*n;

	n = uwu->ray;
	while (n->dof < MAX_DOF)
	{
		n->mx = (int)(n->rx) / 32;
		n->my = (int)(n->ry) / 32;
		if (n->mx + n->my * uwu->map_s_x > 0 && n->mx < uwu->map_s_x
			&& n->my < uwu->map_s_y
			&& uwu->map[n->my][n->mx] == '1')
		{
			n->vx = n->rx;
			n->vy = n->ry;
			n->dis_v = dist(n->px, n->py, n->vx, n->vy);
			n->dof = MAX_DOF;
		}
		else
		{
			n->rx += n->xo;
			n->ry += n->yo;
			n->dis_v = 1000000;
			n->dof++;
		}
	}
}
