/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:45:33 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/31 21:30:15 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_background(t_game *cub3d)
{
	t_img	*draw;
	int		color;
	t_color	col;
	int		x;
	int		y;

	draw = &cub3d->draw;
	col = cub3d->ceiling;
	color = create_trgb(0, col.red, col.green, col.blue);
	col = cub3d->floor;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		if (y == HEIGHT / 2)
			color = create_trgb(0, col.red, col.green, col.blue);
		while (x < WIDTH)
		{
			put_pxl_on_img(draw, x, y, color);
			++x;
		}
		++y;
	}
}

int	render(t_game *cub3d)
{
	t_mlx	*mlx;

	if (!cub3d->key_press)
		return (1);
	mlx = &cub3d->mlx;
	draw_background(cub3d);
//	draw_map(cub3d);
//	draw_player(cub3d);
//	draw_ray(cub3d);
	render_walls(cub3d);
	// render_minimap(cub3d);
	switch_img(&cub3d->draw, &cub3d->render);
	mlx_put_image_to_window(mlx->disp, mlx->win, &cub3d->render, 0, 0);
	cub3d->key_press = false;
	return (0);
}
