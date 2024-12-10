/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:56:05 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/10 13:30:59 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"

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
	if (cub3d->ready_for_map && cub3d->map)
		return (false);
	print_err("Uncomplete game parameters", 3);
	return (true);
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
	if (uncomplete_params(cub3d)/* || check_map(cub3d->map) == -1*/)
	{
		free_t_game_ptrs(cub3d);
		exit(EXIT_FAILURE);
	}
}
