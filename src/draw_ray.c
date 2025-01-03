/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/03 11:36:29 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	draw_line(t_img *img, t_ivec current, t_ivec end, double ang)
{
	t_dvec	tmp;
	t_dvec	delta;

	delta.x = cos(ang);
	delta.y = sin(ang);
	tmp.x = (double)current.x;
	tmp.y = (double)current.y;
	while (current.x != end.x && current.y != end.y)
	{
		tmp.x += delta.x;
		tmp.y += delta.y;
		current.x = floor(tmp.x);
		current.y = floor(tmp.y);
		put_pxl_on_img(img, current.x, current.y, 0x00aa0000);
	}
}

void	draw_ray(t_game *cub3d)
{
	t_ivec	start;
	t_ivec	end;
	double	current_ang;
	int		i;

	i = (FOV / 2) * -1;
	start.x = cub3d->player.x;
	start.y = cub3d->player.y;
	while (i <= FOV / 2)
	{
		current_ang = cub3d->player.ang + deg_to_rad(i);
		end = end_ray(start, current_ang, cub3d->map);  
		draw_line(&cub3d->images, start, end, current_ang);
		++i;
		if (i == 4)
			break ;
	}
}
