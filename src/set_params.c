/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:56:05 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/08 11:05:21 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"

static void	check_file_extension(char *filename, t_game *cub3d)
{
	if (ft_check_extension(filename, ".cub"))
	{
		print_error(E_WEXT, cub3d);
		exit(2);
	}
}

static int	open_source_file(char *filename, t_game *cub3d)
{
	int	fd;

	if (access(filename, F_OK | R_OK))
		clean_exit(cub3d, strerror(errno), 2);
	check_file_extension(filename, cub3d);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		clean_exit(cub3d, strerror(errno), 3);
	return (fd);
}

static bool	uncomplete_params(t_game *cub3d)
{
	if (!cub3d->no.data.img || !cub3d->so.data.img || !cub3d->ea.data.img
		|| !cub3d->we.data.img)
		return (true);
	if (cub3d->ready_for_map && cub3d->map)
		return (false);
	print_error(E_UPARAM, cub3d);
	return (true);
}

static void	read_source_file(char *filename, t_game *cub3d)
{
	char	*line;
	int		fd;

	fd = open_source_file(filename, cub3d);
	line = get_next_line(fd);
	while (line)
	{
		if (extract_params(&line, cub3d) == -1)
			break ;
		line = get_next_line(fd);
	}
	close(fd);
	if (uncomplete_params(cub3d))
		clean_exit(cub3d, NULL, 2);
}

void	set_game_params(char *filename, t_game *cub3d)
{
	read_source_file(filename, cub3d);
	set_player(cub3d);
	validate_map(cub3d);
}
