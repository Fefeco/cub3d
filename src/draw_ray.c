/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/24 17:13:37 by fcarranz         ###   ########.fr       */
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

double deg_to_rad(int deg) {
    return deg * (M_PI / 180.0);
}

int rad_to_deg(double rad) {
    return (int)(rad * (180.0 / M_PI));
} 

void	draw_ray(t_game *cub3d)
{
	t_player	*ply;
	t_player	pt;
	int			x;
	int			y;
	int			i = -29;

	ply = &cub3d->player;
	pt = *ply;
	x = ply->x;
	y = ply->y;
	if (ply->prnt_ray_info)
		printf("Ray from - to\n--------\ndy:%f dx:%f\ny: %d x: %d\n", ply->dy, ply->dx, y, x);
	while (i <= 30)
	{
		pt.ang = ply->ang + deg_to_rad(i);
		if (ply->prnt_ray_info)
			printf("Angle: %d - Sumo: %f radianes que son %d grados\n", 
			(rad_to_deg(pt.ang)), 
			(deg_to_rad(i)), 
			i);
		pt.dx = cos(pt.ang);
		pt.dy = sin(pt.ang);
		draw_line(&cub3d->images, pt);
		++i;
	}
	if (ply->prnt_ray_info)
	{
		printf("y: %d x: %d\n--------\n\n", y, x);
		ply->prnt_ray_info = 0;
	}
}
