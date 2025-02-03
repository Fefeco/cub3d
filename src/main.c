/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:57:47 by davifer2          #+#    #+#             */
/*   Updated: 2025/02/03 11:40:45 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	cub3d;

	if (argc != 2 || !argv[1][0])
	{
		print_error(E_WARGS);
		return (1);
	}
	init_t_game(&cub3d);
	cub3d.mlx.disp = mlx_init();
	if (!cub3d.mlx.disp)
	{
		print_error(E_NODISP);
		return (-1);
	}
	set_game_params(argv[1], &cub3d);
	init_game(&cub3d);
	return (0);
}
