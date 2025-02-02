/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:00:35 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/02 11:43:46 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_game_ptrs(t_game *cub3d)
{
	free_texture(&cub3d->no, &cub3d->mlx.disp);
	free_texture(&cub3d->so, &cub3d->mlx.disp);
	free_texture(&cub3d->ea, &cub3d->mlx.disp);
	free_texture(&cub3d->we, &cub3d->mlx.disp);
	free_image(&cub3d->render, cub3d->mlx.disp);
	free_image(&cub3d->draw, cub3d->mlx.disp);
	free_mlx(&cub3d->mlx);
	free_map(cub3d->map);
}

int	clean_exit(t_game *cub3d, const char *error, int nb_error)
{
	print_error(error);
	clean_game_ptrs(cub3d);
	exit(nb_error);
}
