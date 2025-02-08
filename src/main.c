/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:57:47 by davifer2          #+#    #+#             */
/*   Updated: 2025/02/08 11:15:59 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "colors.h"

int	main(int argc, char **argv)
{
	t_game	cub3d;

	if (argc != 2 || !argv[1][0])
	{
		ft_putstr_fd(RED, 2);
		ft_putendl_fd("Error", 2);
		ft_putstr_fd(E_WARGS, 2);
		ft_putendl_fd(RESET, 2);
		return (1);
	}
	init_t_game(&cub3d);
	cub3d.mlx.disp = mlx_init();
	if (!cub3d.mlx.disp)
	{
		print_error(E_NODISP, &cub3d);
		return (-1);
	}
	set_game_params(argv[1], &cub3d);
	init_game(&cub3d);
	return (0);
}
