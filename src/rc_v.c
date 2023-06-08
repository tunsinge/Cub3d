/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_v.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:18:38 by mdoumi            #+#    #+#             */
/*   Updated: 2023/06/08 13:04:16 by mdoumi           ###   ########.fr       */
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
		n->rx = (((int)n->px / uwu->map_s) * uwu->map_s) - 0.0001;
		n->ry = (n->px - n->rx) * n->ntan + n->py;
		n->xo = -uwu->map_s;
		n->yo = -n->xo * n->ntan;
	}
	else if (n->ra < P2 || n->ra > P3)
	{
		n->rx = (((int)n->px / uwu->map_s) * uwu->map_s) + uwu->map_s;
		n->ry = (n->px - n->rx) * n->ntan + n->py;
		n->xo = uwu->map_s;
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
		n->mx = (int)(n->rx) / uwu->map_s;
		n->my = (int)(n->ry) / uwu->map_s;
		if (n->mx >= 0 && n->my >= 0 && n->mx < uwu->map_s_x
			&& n->my < uwu->map_s_y
			&& !is_transparent(uwu->map[n->my][n->mx]))
		{
			if (uwu->map[n->my][n->mx] == '4')
				uwu->ray->is_door[1] = 1;
			(void)0,n->vx = n->rx,n->vy = n->ry,n->dof = MAX_DOF;
			n->dis_v = dist(n->px, n->py, n->vx, n->vy);
		}
		else
			(void)0,n->rx += n->xo,n->ry += n->yo,n->dis_v=B,n->dof++;
	}
}
