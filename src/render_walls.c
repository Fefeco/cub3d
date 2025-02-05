/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:48:54 by fedeito           #+#    #+#             */
/*   Updated: 2025/02/05 13:28:47 by fcarranz         ###   ########.fr       */
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
	int		color;

	pixel = data->addr + (y * data->line_len + x * (data->bits_x_pxl / 8));
	color = *(int *)pixel;
	return (color);
}

void draw_wall(t_game *cub3d, int x, t_wall wall, t_ray ray, double ray_dst)
{
	int	y;
	int	wall_end;
	t_tex	*tex;
	double	hit_y;
	double	hit_x;
	double	tex_x;
	double	tex_y;

	tex = get_data_texture(cub3d, ray);
	wall_end = wall.start + wall.line_height;
	hit_y = ray.start.y + ray.delta.y * ray_dst;
	hit_x = ray.start.x + ray.delta.x * ray_dst;
	if (ray.axis == 'x')
		tex_x = fmod(hit_y, TILE);
	else
		tex_x = fmod(hit_x, TILE);
	if (tex_x < 0)
		tex_x += TILE;
	tex_x = (tex_x * tex->w) / TILE;
	if (wall_end > HEIGHT)
		wall_end = HEIGHT;
	if (wall.start < 0)
	{
		tex_y = ((wall.start * -1) * tex->h) / wall.line_height;
		wall.start = 0;
	}
	y = wall.start;
	while (y < wall_end)
	{
		put_pxl_on_img(&cub3d->draw, x, y, get_pixel_color(&tex->data, (int)tex_x, (int)tex_y));
		tex_y += (double)tex->h / wall.line_height;
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
		draw_wall(cub3d, x, wall, ray, ray.dst);
		ray.ang += increment;
	}
}
