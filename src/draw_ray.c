/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/29 17:23:07 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	draw_line(t_img *img, t_player pt)
{
	float	fx;
	float	fy;
	int		i;

	fx = pt.x;
	fy = pt.y;
	i = 0;
	while (i++ < 50)
	{
		fx += pt.dx;
		fy += pt.dy;
		pt.x = floor(fx);
		pt.y = floor(fy);
		put_pxl_on_img(img, pt.x, pt.y, 0x00AA0000);
	}
}

void	draw_ray(t_game *cub3d)
{
	t_player	pt;
	int			i;

	i = (FOV / 2) * -1;
	pt = cub3d->player;
	while (i <= FOV / 2)
	{
		pt.dx = cos(pt.ang + deg_to_rad(i));
		pt.dy = sin(pt.ang + deg_to_rad(i));
		draw_line(&cub3d->images, pt);
		++i;
	}
}
