/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/16 14:05:08 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

bool	hit(t_dvec point, char **map)
{
	if (map[point.y / TILE][point.x / TILE] == '1')
		return (true);
	return (false);
}

void	draw_line(t_img *img, t_ivec curr_pos, char **map, double ang)
{
	t_dvec	delta;
	t_dvec	tmp;
	int		i;

	i = -1;
	tmp.x  = curr_pos.x;
	tmp.y  = curr_pos.y;
	set_deltas(&delta, ang);
}

void	draw_ray(t_game *cub3d)
{
	t_ivec	ply;
	t_dvec	tmp;
	t_dvec	delta;

	set_deltas(delta, cub3d->player.ang);
	tmp.x = cub3d->player.x;
	tmp.y = cub3d->player.y;
	while (!hit(tmp, cub3d->map))
	{
		tmp.x += delta.x;
		tmp.y += delta.y;
		put_pxl_on_img(img, floor(tmp.x), floor(tmp.y), 0x00AA0000);
	}
}
