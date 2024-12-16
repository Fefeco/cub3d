/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:10:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/16 14:20:02 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

void	create_image(t_game *cub3d)
{
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
}
