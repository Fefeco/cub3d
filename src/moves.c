/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:26:14 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/28 20:47:35 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

int	check_wall(int x, int y, char **map)
{
	if (!map || map[y / TILE][x / TILE] == '1')
		return (1);
	return (0);
}

void	try_move_x(int key, t_game *cub3d)
{
	int	step;
	int x;
	int y;

	x = cub3d->player.x;
	y = cub3d->player.y;
	step = STEP_SZ;
	if (key == KEY_A)
		step *= -1;
	if (x + step < 0 || x + step >= WIDTH || check_wall(x + step, y, cub3d->map))
		return ;
	cub3d->player.x += step;
}

void	try_move_y(int key, t_game *cub3d)
{
	int x;
	int y;
	double	dx;
	double	dy;

	x = cub3d->player.x;
	y = cub3d->player.y;
	dx = cub3d->player.dx;
	dy = cub3d->player.dy;
	if (key == KEY_S)
	{
		dx *= -1;
		dy *= -1;
	}
	if (check_wall(x + dx, y + dy, cub3d->map))
		return ;
//	printf("Delta x: %.1f\nDelta y: %.1f\n", dx, dy);
	cub3d->player.x += dx;
	cub3d->player.y += dy;
}

void	rotate(int key, t_player *ply)
{
	double	move_degree;

	move_degree = 10 * (M_PI / 180);
	if (key == LEFT)
		move_degree *= -1;
	ply->ang += move_degree;
	ply->ang = fmod(ply->ang, 2 * M_PI);
	if (ply->ang < 0)
		ply->ang += 2 * M_PI;
	ply->dx = cos(ply->ang);
	ply->dy = sin(ply->ang);
	printf("Actual angle: %.0f\n", ply->ang * (180 / M_PI));
}
