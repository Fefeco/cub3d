/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/28 20:53:30 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	draw_line(t_img *img, t_player pt)
{
	int	i = 0;

	pt.fx = pt.x;
	pt.fy = pt.y;
	while (i++ < 50)
	{

		pt.fx += pt.dx;
		pt.fy += pt.dy;
		pt.x = floor(pt.fx);
		pt.y = floor(pt.fy);
		put_pxl_on_img(img, pt.x, pt.y, 0x00AA0000);
	}
}

void	draw_ray(t_game *cub3d)
{
	t_player	*ply;
	t_player	pt;
	int			i = -29;

	ply = &cub3d->player;
	pt = *ply;
	while (i <= 30)
	{
		pt.ang = ply->ang + deg_to_rad(i);
		pt.dx = cos(pt.ang);
		pt.dy = sin(pt.ang);
		draw_line(&cub3d->images, pt);
		++i;
	}
}
