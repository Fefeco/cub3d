/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:53:09 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/23 21:12:54 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_minimap(t_game *cub3d)
{
	int	mini_w;
	int	mini_h;
	int		color;
	t_ivec	axis;

	mini_w = (WIDTH / 100) * 10;
	mini_h = (HEIGHT / 100) * 10;
	axis.y = 0;
	color = create_trgb(0, 0, 0, 0);
	while (axis.y < mini_h)
	{
		axis.x = 0;
		while (axis.x < mini_w)
		{
			if (axis.x == 0 || axis.x == mini_w - 1 || axis.y == 0 || axis.y == mini_h - 1)
				put_pxl_on_img(&cub3d->images, axis.x, axis.y, color);
			++axis.x;
		}
		++axis.y;
	}
}
