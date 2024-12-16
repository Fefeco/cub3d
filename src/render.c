/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:45:33 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/16 14:21:07 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	put_pxl_on_img(t_img *images, int x, int y, int color)
{
	char	*dst;

	dst = images->addr_to_draw + (y * images->line_length
			+ x * (images->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
static void	put_pxl_on_img(t_img *images, int x, int y, int color)
{
	char	*dst;

	dst = images->addr_to_draw + (y * images->line_length
			+ x * (images->bits_per_pixel / 8));
	dst = color;
}
static void	draw_background(t_game *cub3d)
{
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
}

int	render(t_game *cub3d)
{
	t_img	*images;
	t_mlx	*mlx;

	images = &cub3d->images;
	mlx = &cub3d->mlx;
	draw_background(cub3d);
	switch_img(images);
	mlx_put_image_to_window(mlx->disp, mlx->win, images->img_to_render, 0, 0);
	return (0);
}
