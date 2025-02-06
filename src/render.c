/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:45:33 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 11:49:16 by fcarranz         ###   ########.fr       */
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
	t_img	*render;
	t_img	*draw;

	if (!cub3d->key_press)
		return (1);
	mlx = &cub3d->mlx;
	render = &cub3d->render;
	draw = &cub3d->draw;
	draw_background(cub3d);
	render_walls(cub3d);
	switch_img(draw, render);
	mlx_put_image_to_window(mlx->disp, mlx->win, render->img, 0, 0);
	cub3d->key_press = false;
	return (0);
}
