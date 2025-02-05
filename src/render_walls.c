/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:48:54 by fedeito           #+#    #+#             */
/*   Updated: 2025/02/05 21:27:24 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

t_tex	*get_data_texture(t_game *cub3d, t_ray ray)
{
	if (ray.axis == 'x')
	{
		if (ray.step.x > 0)
			return (&cub3d->ea);
		else
			return (&cub3d->we);
	}
	else
	{
		if (ray.step.y > 0)
			return (&cub3d->so);
		else
			return (&cub3d->no);
	}
}
int get_pixel_color(t_img *data, int x, int y)
{
	char	*pixel = NULL;

	pixel = data->addr + (y * data->line_len + x * (data->bits_x_pxl / 8));
	return (*(unsigned int *)pixel);
}

void draw_wall(t_game *cub3d, int x, t_wall wall, t_ray ray)
{
	int		y;
	t_tex	*texture;
	t_dvec	tex;

	texture = get_data_texture(cub3d, ray);
	ray.hit.y = ray.start.y + ray.delta.y * ray.dst;
	ray.hit.x = ray.start.x + ray.delta.x * ray.dst;
	if (ray.axis == 'x')
		tex.x = fmod(ray.hit.y, TILE);
	else
		tex.x = fmod(ray.hit.x, TILE);
	if (tex.x < 0)
		tex.x += TILE;
	tex.x = (tex.x * texture->w) / TILE;
	if (wall.start < 0)
	{
		tex.y = ((wall.start * -1) * texture->h) / wall.line_height;
		wall.start = 0;
	}
	else
		tex.y = 0;
	y = wall.start;
	while (y < wall.end)
	{
		wall.px_color = get_pixel_color(&texture->data, (int)tex.x, (int)tex.y);
		put_pxl_on_img(&cub3d->draw, x, y, wall.px_color);
		tex.y += (double)texture->h / wall.line_height;
		++y;
	}
}

static double	del_fish_eye(double ray_dst, double ray_ang, double ply_ang)
{
	return (HEIGHT / (ray_dst * cos(ray_ang - ply_ang)) * TILE);
}

void	render_walls(t_game *cub3d)
{
	int		x;
	t_ray	ray;
	double	increment;
	t_wall	wall;

	ray.start = cub3d->ply.pos;
	ray.ang = cub3d->ply.ang - (deg_to_rad(FOV) / 2);
	increment = deg_to_rad(FOV) / WIDTH;
	x = -1;
	while (++x < WIDTH)
	{
		set_deltas(&ray.delta, ray.ang);
		dda(&ray, cub3d->map);
		wall.line_height = del_fish_eye(ray.dst, ray.ang, cub3d->ply.ang);
		wall.start = HEIGHT / 2 - (wall.line_height / 2);
		wall.end = wall.start + wall.line_height;
		if (wall.end > HEIGHT)
			wall.end = HEIGHT;
		draw_wall(cub3d, x, wall, ray);
		ray.ang += increment;
	}
}
