/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:48:54 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/30 11:33:00 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void draw_wall(t_game *cub3d, int x, t_wall wall)
{
    int y;
    int wall_end;

    wall_end = wall.start + wall.line_height;
    if (wall.start < 0)
        wall.start = 0;
    if (wall_end > HEIGHT)
	{
        wall_end = HEIGHT;
	}
	y = wall.start;
    while (y < wall_end)
    {
        put_pxl_on_img(&cub3d->images, x, y, wall.color);
		++y;
    }
}

void	render_walls(t_game *cub3d)
{
	int		x;
	t_ray	ray;
	double	ray_dst;
	double	inc;
	t_wall	wall;

	ray.start = cub3d->ply.pos;
	ray.ang = cub3d->ply.ang - (deg_to_rad(FOV) / 2);
	inc = deg_to_rad(FOV) / WIDTH;
	x = -1;
	while (++x < WIDTH)
	{
		if (x == 668)
		{
			printf ("ray_dst:%.03f\n", ray_dst);
			printf ("posx:%.03f posy:%.03f\n", ray.start.x, ray.start.y);
		}
		set_deltas(&ray.delta, ray.ang);
		ray_dst = dda(ray, cub3d->map);
		wall.line_height = (HEIGHT / ray_dst);
		wall.color = get_wall_color(ray_dst);
		wall.start = HEIGHT / 2 - (wall.line_height / 2);
		draw_wall(cub3d, x, wall);
		ray.ang += inc;
	}
}
