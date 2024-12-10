/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:57:47 by davifer2          #+#    #+#             */
/*   Updated: 2024/12/10 13:21:11 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_t_game_ptrs(t_game *cub3d)
{
	cub3d->textures.NO = NULL;
	cub3d->textures.SO = NULL;
	cub3d->textures.WE = NULL;
	cub3d->textures.EA = NULL;
	cub3d->ceiling.red = -1;
	cub3d->ceiling.green = -1;
	cub3d->ceiling.blue = -1;
	cub3d->floor.red = -1;
	cub3d->floor.green = -1;
	cub3d->floor.blue = -1;
	cub3d->ready_for_map = false;
	cub3d->map = NULL;
}

int	main(int argc, char **argv)
{
	t_game	cub3d;

	if (argc != 2 || !argv[1][0])
		return (print_err("Invalid number of arguments", 1));
	init_t_game_ptrs(&cub3d);
	set_game_params(argv[1], &cub3d);	// Load params from .cub file
	// init_game();						// Game initialization
	free_t_game_ptrs(&cub3d);
	return (0);
}
