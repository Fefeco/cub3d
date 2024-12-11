/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:50:22 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/11 22:19:11 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "colors.h"

void	init_game(t_game *cub3d)
{
	void	*connection;
	void	*window;

	(void) cub3d;
	connection = mlx_init();
	if (!connection)
		return ;
	ft_printf(YELL"Connection stablished!\n"RESET);
	window = mlx_new_window(connection, WIDTH, HEIGTH, "CUB3D");
	mlx_loop(connection);

	mlx_destroy_window(connection, window);
	mlx_destroy_display(connection);
	free (connection);
}
