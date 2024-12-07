/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:56:05 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/07 14:04:37 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"

static void	test(const t_game *cub3d)
{
//	const t_coords	*tx;
	const t_color	*C;
	const t_color	*F;

	C = &cub3d->ceiling;
	F = &cub3d->floor;
//	tx = &cub3d->textures;
	ft_printf("======================\n         TEST         \n======================\n");

//	ft_printf("\nTEXTURES\n---------\n");
//	ft_printf("  NO: %s\n  SO: %s\n  WE: %s\n  EA: %s\n\n", tx->NO, tx->SO, tx->WE, tx->EA);
	ft_printf("\nCOLORS\n-----------\n");
	ft_printf("\n-----CEILING-----\n");
	ft_printf("RGB: %i,%i,%i\nRED: %i\nGREEN: %i\nBLUE: %i\n", C->red, C->green, C->blue, C->red, C->green, C->blue);
	ft_printf("\n-----FLOOR-----\n");
	ft_printf("RGB: %i,%i,%i\nRED: %i\nGREEN: %i\nBLUE: %i\n", F->red, F->green, F->blue, F->red, F->green, F->blue);
	ft_printf("======================\n       END  TEST       \n======================\n");
}

static void	check_game_file(char *filename, int *fd)
{
	if (ft_check_extension(filename, ".cub"))
		exit_err("Invalid extension", 1);
	if (access(filename, F_OK | R_OK))
		exit_err(strerror(errno), 1);
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		exit_err(strerror(errno), 2);
}

static bool	uncomplete_params(t_game *cub3d)
{
	t_coords	*textures;

	textures = &cub3d->textures;
	if (!cub3d->map)
		return (true);
	if (!textures->NO || !textures->SO || !textures->WE || !textures->EA)
		return (true);
	return (false);
}

void	set_game_params(char *filename, t_game *cub3d)
{
	int		fd;
	char	*line;

	check_game_file(filename, &fd);
	line = get_next_line(fd);
	while (line)
	{
		if (extract_params(&line, cub3d) == -1)
			break ;
		line = get_next_line(fd);
	}
	close(fd);
	test(cub3d);	// Prints game data;
	if (uncomplete_params(cub3d))
	{
		free_t_game_ptrs(cub3d);
		print_err("Uncomplete map", 3);
		exit(EXIT_FAILURE);
	}
}
