/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:57:47 by davifer2          #+#    #+#             */
/*   Updated: 2024/12/04 10:31:08 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_t_game_ptrs(t_game *cub3d)
{
	cub3d->textures.NO = NULL;
	cub3d->textures.SO = NULL;
	cub3d->textures.WE = NULL;
	cub3d->textures.EA = NULL;
	cub3d->map = NULL;
}

int	main(int argc, char **argv)
{
	t_game	cub3d;

	if (argc != 2 || !argv[1][0])
		return (print_err("Invalid number of arguments", 1));
	init_t_game_ptrs(&cub3d);
	set_game_params(argv[1], &cub3d); 	// Load params from .cub file
	// init_game();						// Game initialization
	return (0);
}
