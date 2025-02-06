/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:26:14 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 11:23:34 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

void	try_move(int key, t_game *cub3d)
{
	t_dvec	delta;
	t_dvec	ply;
	t_dvec	sum;
	double	ang;

	sum.x = 0;
	sum.y = 0;
	if (key == KEY_A || key == KEY_D)
		ang = norm_ang(cub3d->ply.ang + deg_to_rad(90));
	else
		ang = cub3d->ply.ang;
	set_deltas(&delta, ang);
	if (key == KEY_S || key == KEY_A)
	{
		delta.x *= -1;
		delta.y *= -1;
	}
	if (delta.x < 0)
		sum.x = -1;
	if (delta.y < 0)
		sum.y = -1;
	ply.x = cub3d->ply.pos.x + (delta.x * STEP_SZ);
	ply.y = cub3d->ply.pos.y + (delta.y * STEP_SZ);
	if (!check_wall(floor(ply.x + sum.x) / TILE, floor(cub3d->ply.pos.y) / TILE, cub3d->map))
		cub3d->ply.pos.x = ply.x;
	if (!check_wall(floor(cub3d->ply.pos.x) / TILE, floor(ply.y + sum.y) / TILE, cub3d->map))
		cub3d->ply.pos.y = ply.y;
}

void	rotate(int key, t_player *ply)
{
	double	move_degree;

	move_degree = (M_PI / 180) * SPEED_ROT;
	if (key == LEFT)
		move_degree *= -1;
	ply->ang = norm_ang(ply->ang + move_degree);
}
