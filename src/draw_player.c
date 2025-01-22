/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:26:53 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/22 22:34:29 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_game *cub3d)
{
	int	y;
	int	x;
	int	height = 6;

	y = 0;
    while (y < height)
	{
        x = 0;
        while (x < height * 2 - 1)
		{
            int absolute_x = cub3d->ply.pos.x - (height - 1) + x;
            int absolute_y = cub3d->ply.pos.y + y;
            int left_limit = cub3d->ply.pos.x - y;
            int right_limit = cub3d->ply.pos.x + y;
            if (absolute_x >= left_limit && absolute_x <= right_limit)
				put_pxl_on_img(&cub3d->images, absolute_x, absolute_y, 0x00000000);
            x++;
        }
        y++;
    }
}
