/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:10:28 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/31 21:56:53 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

void	create_image(t_game *cub3d)
{
	t_mlx	*mlx;
	t_img	*draw;
	t_img	*render;

	mlx = &cub3d->mlx;
	draw = &cub3d->draw;
	render = &cub3d->render;
	draw->img = mlx_new_image(mlx->disp, WIDTH, HEIGHT);
	render->img = mlx_new_image(mlx->disp, WIDTH, HEIGHT);
	if (!draw->img || !render->img)
		clean_exit(cub3d, E_NEWIMG, 6);
	draw->addr = mlx_get_data_addr(draw->img, &draw->bits_per_pixel,
			&draw->line_length, &draw->endian);
	render->addr = mlx_get_data_addr(render->img,
			&render->bits_per_pixel, &render->line_length, &render->endian);
	if (!draw->img|| !render->img)
		clean_exit(cub3d, E_DATIMG, 6);
}
