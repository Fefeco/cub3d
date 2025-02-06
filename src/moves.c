/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:26:14 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 11:46:28 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

void	try_move(int key, t_game *cub3d)
{
	t_dvec	delta;
	t_dvec	*ply;
	t_dvec	tmp;
	double	ang;

	ply = &cub3d->ply.pos;
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
	tmp.x = ply->x + (delta.x * STEP_SZ);
	tmp.y = ply->y + (delta.y * STEP_SZ);
	if (!check_wall(floor(tmp.x) / TILE, floor(ply->y) / TILE, cub3d->map))
		ply->x = tmp.x;
	if (!check_wall(floor(ply->x) / TILE, floor(tmp.y) / TILE, cub3d->map))
		ply->y = tmp.y;
}

void	rotate(int key, t_player *ply)
{
	double	move_degree;

	move_degree = (M_PI / 180) * SPEED_ROT;
	if (key == LEFT)
		move_degree *= -1;
	ply->ang = norm_ang(ply->ang + move_degree);
}
