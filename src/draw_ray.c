/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/23 14:46:57 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	draw_line(t_img *img, t_player pt)
{
	int	i = 0;
	while (i++ < 20)
	{
		pt.x += pt.dx;
		pt.y += pt.dy;
		put_pxl_on_img(img, pt.x, pt.y, 0x00AA0000);
	}
}

void	draw_ray(t_game *cub3d)
{
	t_player	*ply;
	t_player	pt;
	int			x;
	int			y;
	int			i = -15;

	ply = &cub3d->player;
	pt = *ply;
	x = ply->x;
	y = ply->y;
	if (ply->prnt_ray_info)
		printf("Ray from - to\n--------\ndy:%f dx:%f\ny: %d x: %d\n", ply->dy, ply->dx, y, x);
	while (i++ <= 15)
	{
		pt.ang += i * (M_PI / 180);
		pt.dx = cos(pt.ang);
		pt.dy = sin(pt.ang);
		draw_line(&cub3d->images, pt);
	}
	if (ply->prnt_ray_info)
	{
		printf("y: %d x: %d\n--------\n\n", y, x);
		ply->prnt_ray_info = 0;
	}
}
