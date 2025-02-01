/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:45:33 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/01 11:39:58 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_background(t_game *cub3d)
{
	// Function to change
	t_img	*images;
	int		color;
	t_color	col;
	int		x;
	int		y;

	images = &cub3d->images;
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
			put_pxl_on_img(images, x, y, color);
			++x;
		}
		++y;
	}
	// To

	t_iimg	*draw;
	//int		color;
	//t_color	col;
	//int		x;
	//int		y;

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
			put_pxl_on_iimg(draw, x, y, color);
			++x;
		}
		++y;
	}
	// End
}

int	render(t_game *cub3d)
{
	t_img	*images;
	t_mlx	*mlx;

	if (!cub3d->key_press)
		return (1);
	// Line to change
	images = &cub3d->images;
	// To
	t_iimg *render;
	t_iimg *draw;
	render = &cub3d->render;
	draw = &cub3d->draw;
	// End
	mlx = &cub3d->mlx;
	draw_background(cub3d);
	render_walls(cub3d);
	// Function to change
	switch_img(images);
	// To
	switch_iimg(draw, render);
	//End


	// Function to change
	//mlx_put_image_to_window(mlx->disp, mlx->win, images->img_to_render, 0, 0);
	// To
	mlx_put_image_to_window(mlx->disp, mlx->win, render->img, 0, 0);
	// End
	cub3d->key_press = false;
	return (0);
}
