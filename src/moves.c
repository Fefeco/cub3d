/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:26:14 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/08 13:38:58 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

int	norm_pos(double delta)
{
	if (delta < 0) 
		return (1);
	else if (delta == 0)
		return (0);
	return (-1);
}

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
		//ply->x = tmp.x + norm_pos(delta.x);
		ply->x = tmp.x;
	if (!check_wall(floor(ply->x) / TILE, floor(tmp.y) / TILE, cub3d->map))
		//ply->y = tmp.y + norm_pos(delta.y);
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

int	handle_key_press(int key, t_game *cub3d)
{
	if (key == ESC)
		clean_exit(cub3d, NULL, 0);
	else if (key == LEFT)
		cub3d->keys.left = true;
	else if (key == RIGHT)
		cub3d->keys.right = true;
	else if (key == KEY_A)
		cub3d->keys.a = true;
	else if (key == KEY_D)
		cub3d->keys.d = true;
	else if (key == KEY_W)
		cub3d->keys.w = true;
	else if (key == KEY_S)
		cub3d->keys.s = true;
	return (0);
}

int	handle_key_release(int key, t_game *cub3d)
{
	if (key == LEFT)
		cub3d->keys.left = false;
	else if (key == RIGHT)
		cub3d->keys.right = false;
	else if (key == KEY_A)
		cub3d->keys.a = false;
	else if (key == KEY_D)
		cub3d->keys.d = false;
	else if (key == KEY_W)
		cub3d->keys.w = false;
	else if (key == KEY_S)
		cub3d->keys.s = false;
	return (0);
}
