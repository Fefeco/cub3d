/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:26:14 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/27 13:51:39 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

void	try_move(int key, t_game *cub3d)
{
	t_dvec	delta;
	t_dvec	ply;
	double	ang;
	double	sumax;
	double	sumay;

	sumax = 0;
	sumay = 0;
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
		sumax = -1;
	if (delta.y < 0)
		sumay = -1;
	ply.x = cub3d->ply.pos.x + delta.x;
	ply.y = cub3d->ply.pos.y + delta.y;
	if (!check_wall(floor(ply.x + sumax) / TILE, floor(cub3d->ply.pos.y) / TILE, cub3d->map))
		cub3d->ply.pos.x = ply.x;
	if (!check_wall(floor(cub3d->ply.pos.x) / TILE, floor(ply.y + sumay) / TILE, cub3d->map))
		cub3d->ply.pos.y = ply.y;
}

void	rotate(int key, t_player *ply)
{
	double	move_degree;

	move_degree = M_PI / 180;
	if (key == LEFT)
		move_degree *= -1;
	ply->ang = norm_ang(ply->ang + move_degree);
}
