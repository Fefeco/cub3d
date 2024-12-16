/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:57:47 by davifer2          #+#    #+#             */
/*   Updated: 2024/12/16 11:27:46 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	cub3d;

	if (argc != 2 || !argv[1][0])
		return (clean_exit(&cub3d, E_WARGS, 1));
	init_t_game_ptrs(&cub3d);
	set_game_params(argv[1], &cub3d);	// Load params from .cub file
	init_game(&cub3d);						// Game initialization
	clean_game_ptrs(&cub3d);
	return (0);
}
