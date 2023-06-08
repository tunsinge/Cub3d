/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_v.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:24:58 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/06/08 09:25:00 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical(t_cub3d *uwu, t_ray *rays)
{
	t_ray	*n;

	((void)0, n = rays, n->dof = 0, n->vx = n->px, n->vy = n->py);
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
	vertical2(uwu, rays);
}

void	vertical2(t_cub3d *uwu, t_ray *rays)
{
	t_ray	*n;

	n = rays;
	while (n->dof < MAX_DOF)
	{
		n->mx = (int)(n->rx) / uwu->map_s;
		n->my = (int)(n->ry) / uwu->map_s;
		if (n->mx >= 0 && n->my >= 0 && n->mx < uwu->map_s_x
			&& n->my < uwu->map_s_y
			&& (uwu->map[n->my][n->mx] > '0'))
		{
			rays->is_door = (uwu->map[n->my][n->mx] == '4')
				+ (uwu->map[n->my][n->mx] == '2') * 2;
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
