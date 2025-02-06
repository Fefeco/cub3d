/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:10:28 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 10:54:25 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

void	create_image(t_game *cub3d)
{
	t_img	*render;
	t_img	*draw;
	void	*disp;

	render = &cub3d->render;
	draw = &cub3d->draw;
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
}
