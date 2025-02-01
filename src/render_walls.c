/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:48:54 by fedeito           #+#    #+#             */
/*   Updated: 2025/02/01 13:47:37 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

// Function to change
t_iimg	*get_textures(t_game *cub3d, t_ray ray)
{
	if (ray.axis == 'x')
	{
		if (ray.step.x > 0)
			return (cub3d->tex.img_ea);
		else
			return (cub3d->tex.img_we);
	}
	else
	{
		if (ray.step.y > 0)
			return (cub3d->tex.img_so);
		else
			return (cub3d->tex.img_no);
	}
}

int get_pixel_colors(t_iimg *img, int x, int y)
{
	char			*pixel;
	int				color;

	pixel = img->addr_to_draw + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(int *)pixel;
	return (color);
}
// To
t_img	*get_data_texture(t_game *cub3d, t_ray ray)
{
	if (ray.axis == 'x')
	{
		if (ray.step.x > 0)
			return (&cub3d->ea.data);
		else
			return (&cub3d->we.data);
	}
	else
	{
		if (ray.step.y > 0)
			return (&cub3d->so.data);
		else
			return (&cub3d->no.data);
	}
}
int get_pixel_color(t_img *data, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = data->addr + (y * data->line_len + x * (data->bits_x_pxl / 8));
	color = *(int *)pixel;
	return (color);
}
//End


void draw_wall(t_game *cub3d, int x, t_wall wall, t_ray ray, double ray_dst)
{
	int	y;
	int	wall_end;
	// Variable to change
	//t_iimg	*texture;
	// To
	t_img	*tex;
	// End
	double	hit_y;
	double	hit_x;
	double	tex_x;
	double	tex_y;

	// Line to change
	//texture = get_textures(cub3d, ray);
	// To
	tex= get_data_texture(cub3d, ray);
	// End
	wall_end = wall.start + wall.line_height;
	hit_y = ray.start.y + ray.delta.y * ray_dst;
	hit_x = ray.start.x + ray.delta.x * ray_dst;
	if (ray.axis == 'x')
		tex_x = fmod(hit_y, TILE);
	else
		tex_x = fmod(hit_x, TILE);
	if (tex_x < 0)
		tex_x += TILE;
	tex_x = (tex_x * cub3d->tex.w) / TILE;
	if (wall_end > HEIGHT)
	{
		wall_end = HEIGHT;
	}
	if (wall.start < 0)
	{
		tex_y = ((wall.start * -1) * cub3d->tex.h) / wall.line_height;
		wall.start = 0;
	}
	y = wall.start;
	while (y < wall_end)
	{
		// Fucntion to change
		//put_pxl_on_img(&cub3d->draw, x, y, get_pixel_colors(texture, (int)tex_x, (int)tex_y));
		// To
		put_pxl_on_img(&cub3d->draw, x, y, get_pixel_color(tex, (int)tex_x, (int)tex_y));
		// End
		tex_y += (double)cub3d->tex.h / wall.line_height;
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
	double	corrected;

	ray.start = cub3d->ply.pos;
	ray.ang = cub3d->ply.ang - (deg_to_rad(FOV) / 2);
	inc = deg_to_rad(FOV) / WIDTH;
	x = -1;
	while (++x < WIDTH)
	{
		set_deltas(&ray.delta, ray.ang);
		ray_dst = dda(&ray, cub3d->map);
		corrected = ray_dst * cos(ray.ang - cub3d->ply.ang);
		wall.line_height = (HEIGHT / corrected) * TILE;
		wall.start = HEIGHT / 2 - (wall.line_height / 2);
		draw_wall(cub3d, x, wall, ray, ray_dst);
		ray.ang += inc;
	}
}
