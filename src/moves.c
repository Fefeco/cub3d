/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:26:14 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/16 16:12:00 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

static void	try_move(t_game *cub3d, int x, int y)
{
	if (check_wall(x / TILE, y / TILE, cub3d->map))
		return ;
	cub3d->player.x = x;
	cub3d->player.y = y;
}

void	try_move_x(int key, t_game *cub3d)
{
	int 	x;
	int 	y;
	double	side_ang;
	double	dx;
	double	dy;

	side_ang = cub3d->player.ang + deg_to_rad(90);
	if (key == KEY_A)
		side_ang -= deg_to_rad(180);
/*	printf("ViewAng: %d - MoveAng: %d\n",
			rad_to_deg(cub3d->player.ang), 
			rad_to_deg(side_ang));*/
	side_ang = norm_ang(side_ang);
	dx = cos(side_ang); 
	dy = sin(side_ang); 
	x = cub3d->player.x;
	y = cub3d->player.y;
	try_move(cub3d, x + (dx * STEP_SZ), y + (dy * STEP_SZ));
}

void	try_move_y(int key, t_game *cub3d)
{
	double	dx;
	double	dy;
	int		x;
	int		y;

	x = cub3d->player.x;
	y = cub3d->player.y;
	dx = cub3d->player.dx;
	dy = cub3d->player.dy;
	if (key == KEY_S)
	{
		dx *= -1;
		dy *= -1;
	}
	try_move(cub3d, x + (dx * STEP_SZ), y + (dy * STEP_SZ));
}

void	rotate(int key, t_player *ply)
{
	double	move_degree;

	move_degree = (M_PI / 180);
	if (key == LEFT)
		move_degree *= -1;
	ply->ang += move_degree;
	ply->ang = norm_ang(ply->ang);
	ply->dx = cos(ply->ang);
	ply->dy = sin(ply->ang);
}
