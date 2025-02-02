/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:45 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/02 11:44:33 by fedeito          ###   ########.fr       */
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
		ft_printf("\t");
		while (*line)
		{
			if (*line != 32)
				ft_printf(TEST1"|");
			else
				ft_printf(" ");
			if (*line == '1')
				ft_printf(TEST3);
			else if (*line == '0')
				ft_printf(TEST2);
			else
				ft_printf(GREEN);
			ft_printf("%c", *line++);
		}
		ft_printf(TEST1"|\n");
		++map;
	}
	ft_printf(RESET);
}

void	test(const t_game *cub3d)
{
	const t_color	*C;
	const t_color	*F;

	C = &cub3d->ceiling;
	F = &cub3d->floor;
	ft_printf(GREEN"======================\n         TEST         \n======================\n"RESET);

	ft_printf(BLUE"\nTEXTURES\n---------\n"RESET);
	ft_printf("  NO: %s\n  SO: %s\n  WE: %s\n  EA: %s\n\n", cub3d->no.file, cub3d->so.file, cub3d->we.file, cub3d->ea.file);
	
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
	ft_printf(GREEN"\n======================\n       END  TEST       \n======================\n"RESET);
}
