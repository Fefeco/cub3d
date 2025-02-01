/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:10:28 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/01 11:01:43 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

void	create_image(t_game *cub3d)
{
	// Function to change
	t_img	*images;
	t_mlx	*mlx;

	images = &cub3d->images;
	mlx = &cub3d->mlx;
	images->img_to_draw = mlx_new_image(mlx->disp, WIDTH, HEIGHT);
	images->img_to_render = mlx_new_image(mlx->disp, WIDTH, HEIGHT);
	if (!images->img_to_draw || !images->img_to_render)
		clean_exit(cub3d, E_NEWIMG, 6);
	images->addr_to_draw = mlx_get_data_addr(images->img_to_draw,
			&images->bits_per_pixel, &images->line_length, &images->endian);
	images->addr_to_render = mlx_get_data_addr(images->img_to_render,
			&images->bits_per_pixel, &images->line_length, &images->endian);
	if (!images->img_to_draw || !images->img_to_render)
		clean_exit(cub3d, E_DATIMG, 6);
	// To
	t_iimg	*render;
	t_iimg	*draw;
	void	*disp;

	render = &cub3d->render;
	draw  = &cub3d->draw;
	disp = cub3d->mlx.disp;
	render->img = mlx_new_image(disp, WIDTH, HEIGHT);
	draw->img = mlx_new_image(disp, WIDTH, HEIGHT);
	if (!render->img || !draw->img)
		clean_exit(cub3d, E_NEWIMG, 6);
	render->addr = mlx_get_data_addr(render->img, &render->bits_x_pxl,
			&render->line_len, &render->endian);
	draw->addr = mlx_get_data_addr(draw->img, &draw->bits_x_pxl,
			&draw->line_len, &draw->endian);
	if (!render->img || !draw->img)
		clean_exit(cub3d, E_DATIMG, 6);
	// End
}
