/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:26:14 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/16 19:22:23 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

void	try_move(int key, t_game *cub3d)
{
	t_dvec	delta;
	t_ivec	ply;
	double	ang;

	if (key == KEY_A || key == KEY_D)
		ang = norm_ang(cub3d->player.ang + deg_to_rad(90));
	else
		ang = cub3d->player.ang;
	set_deltas(&delta, ang);
	if (key == KEY_S || key == KEY_A)
	{
		delta.x *= -1;
		delta.y *= -1;
	}
	ply.x = floor(cub3d->player.x + (delta.x * STEP_SZ));
	ply.y = floor(cub3d->player.y + (delta.y * STEP_SZ));
	if (check_wall(ply.x / TILE, ply.y / TILE, cub3d->map))
		return ;
	cub3d->player.x = ply.x;
	cub3d->player.y = ply.y;
}

void	rotate(int key, t_player *ply)
{
	double	move_degree;

	move_degree = M_PI / 180;
	if (key == LEFT)
		move_degree *= -1;
	ply->ang = norm_ang(ply->ang + move_degree);
}
