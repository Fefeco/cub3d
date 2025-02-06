/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:49:08 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 12:56:34 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static t_tex	*get_data_texture(t_game *cub3d, t_ray ray)
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

static int	get_pixel_color(t_img *data, int x, int y)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_len + x * (data->bits_x_pxl / 8));
	return (*(unsigned int *)pixel);
}

static t_dvec	calc_texture_pt(t_ray ray, t_tex *texture, t_wall *wall)
{
	t_dvec	tex;

	if (ray.axis == 'x')
		tex.x = fmod(ray.hit.y, TILE);
	else
		tex.x = fmod(ray.hit.x, TILE);
	if (tex.x < 0)
		tex.x += TILE;
	tex.x = (tex.x * texture->w) / TILE;
	if (wall->start < 0)
	{
		tex.y = ((wall->start * -1) * texture->h) / wall->line_height;
		wall->start = 0;
	}
	else
		tex.y = 0;
	return (tex);
}

void	draw_wall(t_game *cub3d, int x, t_wall wall, t_ray ray)
{
	int		y;
	t_tex	*texture;
	t_dvec	tex;

	texture = get_data_texture(cub3d, ray);
	ray.hit.y = ray.start.y + ray.delta.y * ray.dst;
	ray.hit.x = ray.start.x + ray.delta.x * ray.dst;
	tex = calc_texture_pt(ray, texture, &wall);
	y = wall.start;
	while (y < wall.end)
	{
		wall.px_color = get_pixel_color(&texture->data, (int)tex.x, (int)tex.y);
		put_pxl_on_img(&cub3d->draw, x, y, wall.px_color);
		tex.y += (double)texture->h / wall.line_height;
		++y;
	}
}
