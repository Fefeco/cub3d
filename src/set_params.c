/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:56:05 by fcarranz          #+#    #+#             */
/*   Updated: 2024/11/26 13:49:13 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"

static void	check_game_file(char *filename)
{
	if (ft_check_extension(filename, ".cub"))
		exit_err("Invalid extension", 1);
	if (access(filename, F_OK | R_OK))
		exit_err(strerror(errno), 1);
}

void	set_game_params(char *filename)
{
	int		fd;
	char	*line;

	check_game_file(filename);
	fd  = open(filename, O_RDONLY);
	if (fd == -1)
		exit_err(strerror(errno), 2);
	line = get_next_line(fd);
	ft_printf("%s\n", line);
	free(line);
	close(fd);
}
