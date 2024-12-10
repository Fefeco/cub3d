/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:45 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/10 14:08:30 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "colors.h"

static void	ft_print_map(char **map)
{
	char	*line;

	while (*map)
	{
		line = *map;
		ft_printf(ORANGE"\t|");
		while (*line)
			ft_printf("%c|", *line++);
		if (++*map)
			ft_printf(",\n");
	}
	ft_printf(RESET);
}

void	test(const t_game *cub3d)
{
	const t_coords	*tx;
	const t_color	*C;
	const t_color	*F;

	C = &cub3d->ceiling;
	F = &cub3d->floor;
	tx = &cub3d->textures;
	ft_printf(GREEN"======================\n         TEST         \n======================\n"RESET);

	ft_printf(BLUE"\nTEXTURES\n---------\n"RESET);
	ft_printf("  NO: %s\n  SO: %s\n  WE: %s\n  EA: %s\n\n", tx->NO, tx->SO, tx->WE, tx->EA);
	
	ft_printf(BLUE"\nCOLORS\n-----------\n"RESET);
	ft_printf("\n-----CEILING-----\n");
	ft_printf("RGB: %i,%i,%i\n\tRED: %i\n\tGREEN: %i\n\tBLUE: %i\n", C->red, C->green, C->blue, C->red, C->green, C->blue);
	ft_printf("\n-----FLOOR-----\n");
	ft_printf("RGB: %i,%i,%i\n\tRED: %i\n\tGREEN: %i\n\tBLUE: %i\n", F->red, F->green, F->blue, F->red, F->green, F->blue);

	if (cub3d->map)
	{
		ft_printf(BLUE"\nMAP\n--------------\n"RESET);
		ft_print_map(cub3d->map);
	}
	else 
		ft_printf(RED"\nNO MAP\n-----------\n"RESET);
	ft_printf(GREEN"======================\n       END  TEST       \n======================\n"RESET);
}
