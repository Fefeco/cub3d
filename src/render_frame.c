/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:48:54 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/22 23:09:52 by fedeito          ###   ########.fr       */
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
	    printf("Drawing wall at x: %d from y: %d to y: %d with color %d\n", x, wall.start, wall_end, wall.color);
}

void	render_frame(t_game *cub3d)
{
	int		x;
	t_ray	ray;
	double	ray_dst;
	t_wall	wall;

	ray.start = cub3d->ply.pos;
	x = -1;
	while (++x < WIDTH)
	{
		ray.ang = cub3d->ply.ang + atan((x - WIDTH / 2) / deg_to_rad(FOV));
		printf("Ray ang: %f\n", ray.ang);
		ray_dst = dda(ray, cub3d->map);
		printf("Ray distance: %f\n", ray_dst);
		wall.line_height = (int)(HEIGHT / ray_dst);
		wall.color = get_wall_color(ray_dst);
		printf("Wall color: %d\n", wall.color);  // Verifica el color calculado
		wall.start = HEIGHT / 2 - wall.line_height / 2; 
		draw_wall(cub3d, x, wall);
	}
}
