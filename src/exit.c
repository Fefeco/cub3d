/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:00:35 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/09 14:35:32 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_t_game_ptrs(t_game *cub3d)
{
	char	**map;
	
	if (cub3d->textures.NO)
		free(cub3d->textures.NO);
	if (cub3d->textures.SO)
		free(cub3d->textures.SO);
	if (cub3d->textures.WE)
		free(cub3d->textures.WE);
	if (cub3d->textures.EA)
		free(cub3d->textures.EA);
	if (cub3d->map)
	{
		map = cub3d->map;
		while (map)
			free(map++);
		free(cub3d->map);
	}
	init_t_game_ptrs(cub3d);
}

int	exit_err(const char *error, int ret)
{
	print_err(error, ret);
	exit (ret);
}
