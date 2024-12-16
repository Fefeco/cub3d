/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:00:35 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/16 14:20:06 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_game_ptrs(t_game *cub3d)
{
	free_coords(&cub3d->textures);
	free_images(&cub3d->images, cub3d->mlx.disp);
	free_mlx(&cub3d->mlx);
	free_map(cub3d->map);
}

int	clean_exit(t_game *cub3d, const char *error, int nb_error)
{
	print_error(error);
	clean_game_ptrs(cub3d);
	exit(nb_error);
}
