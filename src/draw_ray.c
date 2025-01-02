/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/02 20:09:33 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	draw_line(t_img *img, t_ivec current, t_ivec end, t_dvec delta)
{
	t_dvec	tmp;

	tmp.x = (double)current.x;
	tmp.y = (double)current.y;
	while (current.x != end.x && current.y != end.y)
	{
		tmp.x += delta.x;
		tmp.y += delta.y;
		current.x = floor(tmp.x);
		current.y = floor(tmp.y);
		put_pxl_on_img(img, current.x, current.y, 0x00AA0000);
	}
}

void	draw_ray(t_game *cub3d)
{
	t_ivec	start;
	t_ivec	end;
	t_dvec	delta;
	int			i;

	i = (FOV / 2) * -1;
	start.x = cub3d->player.x;
	start.y = cub3d->player.y;
	end = end_ray(start, cub3d->player.ang, cub3d->map);  
	while (i <= FOV / 2)
	{
		delta.x = cos(cub3d->player.ang + deg_to_rad(i));
		delta.y = sin(cub3d->player.ang + deg_to_rad(i));
		draw_line(&cub3d->images, start, end, delta);
		++i;
	}
}
