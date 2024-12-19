/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/19 21:22:36 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	draw_6x6(t_img *img, int x, int y)
{
	int	i;
	int	j;

	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
			put_pxl_on_img(img, x + j, y + i, 0x00AA0000);
	}
}

void	draw_ray(t_game *cub3d)
{
	t_player	*ply;
	int			x;
	int			y;
	int			i;

	ply = &cub3d->player;
	x = ply->x;
	y = ply->y;
	i = 0;
	while (i++ < 8)
	{
		x = floor(x + ply->dx);
		y = floor(y + ply->dy);
		put_pxl_on_img(&cub3d->images, x, y, 0x00AA0000);
	}
//	draw_6x6(&cub3d->images, ply->x, ply->y - TILE);
}
