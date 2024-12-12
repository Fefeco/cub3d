/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:10:28 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/12 21:38:09 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_game *cub3d)
{
	t_img	*images;
	t_mlx	*mlx;

	images = &cub3d->images;
	mlx = &cub3d->mlx;
	images->img_to_draw = mlx_new_image(mlx->disp, WIDTH, HEIGHT); 
	images->img_to_render = mlx_new_image(mlx->disp, WIDTH, HEIGHT); 
//	if (!images->img_to_draw || !images->img_to_render)
//		exit_clean(cub3d, errcode, errmsj);	// Implementar
	images->addr_to_draw = mlx_get_data_addr(images->img_to_draw,
												&images->bits_per_pixel,
												&images->line_length,
												&images->endian);
	images->addr_to_render = mlx_get_data_addr(images->img_to_render,
												&images->bits_per_pixel,
												&images->line_length,
												&images->endian);
//	if (!images->img_to_draw || !images->img_to_render)
//		exit_clean(cub3d, errcode, errmsj);	// Implementar
}
