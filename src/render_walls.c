/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:48:54 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/30 14:21:31 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	*get_texture(t_game *cub3d, t_ray ray)
{
	if (ray.axis == 'x')
	{
		if (ray.step.x > 0)
			return (cub3d->xpm_images.ea);
		else
			return (cub3d->xpm_images.we);
	}
	else
	{
		if (ray.step.y > 0)
			return (cub3d->xpm_images.so);
		else
			return (cub3d->xpm_images.no);
	}


}

int get_pixel_color(void *texture, int x, int y)
{
	char *pixel;
	int color;
	t_img	img;

	img.addr_to_draw = mlx_get_data_addr(texture, &img.bits_per_pixel, &img.line_length, &img.endian);
	pixel = img.addr_to_draw + (y * img.line_length + x * (img.bits_per_pixel / 8));
	color = *(int *)pixel;
	return (color);
}


void draw_wall(t_game *cub3d, int x, t_wall wall, t_ray ray, double ray_dst)
{
	int	y;
	int	wall_end;
	void	*texture;
	double	hit_y;
	double	hit_x;
	double	tex_x;
	double	tex_y;

	texture = get_texture(cub3d, ray);
	wall_end = wall.start + wall.line_height;
	hit_y = ray.start.y + ray.delta.y * ray_dst;
	hit_x = ray.start.x + ray.delta.x * ray_dst;
	if (ray.axis == 'y')
		tex_x = (int)hit_y % TILE;
	else
		tex_x = (int)hit_x % TILE;
	tex_x = (tex_x * cub3d->xpm_images.width) / TILE;
	printf("tex_x: %.02f\n", tex_x);
	if (wall.start < 0)
		wall.start = 0;
	if (wall_end > HEIGHT)
	{
		wall_end = HEIGHT;
	}
	y = wall.start;
	while (y < wall_end)
	{
		tex_y = ((y - wall.start) * cub3d->xpm_images.height) / wall.line_height;
		int color = get_pixel_color(texture, tex_x, tex_y);
		put_pxl_on_img(&cub3d->images, x, y, color);
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
		set_deltas(&ray.delta, ray.ang);
		ray_dst = dda(&ray, cub3d->map);
		wall.line_height = (HEIGHT / ray_dst);
		wall.color = get_wall_color(ray_dst);
		wall.start = HEIGHT / 2 - (wall.line_height / 2);
		draw_wall(cub3d, x, wall, ray, ray_dst);
		ray.ang += inc;
	}
}
