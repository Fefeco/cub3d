/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:48:54 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/23 20:12:00 by fedeito          ###   ########.fr       */
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
	    //printf("Drawing wall at x: %d from y: %d to y: %d with color %d\n", x, wall.start, wall_end, wall.color);
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
		//printf("Ray ang: %f\n", ray.ang);
		set_deltas(&ray.delta, ray.ang);
		ray_dst = dda(ray, cub3d->map);
		printf("My Ray distance: %f - Ang: %f\n", ray_dst, ray.ang);
		wall.line_height = (int)(TILE / ray_dst);
		wall.color = get_wall_color(ray_dst);
		wall.start = HEIGHT / 2 - wall.line_height / 2; 
		draw_wall(cub3d, x, wall);
		ray.ang += inc;
	}
}
