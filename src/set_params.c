/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:56:05 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/30 13:28:30 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"

static void	check_file_extension(char *filename)
{
	if (ft_check_extension(filename, ".cub"))
	{
		print_error(E_WEXT);
		exit(2);
	}
}

static int	open_source_file(char *filename)
{
	int	fd;

	if (access(filename, F_OK | R_OK))
	{
		print_error(strerror(errno));
		exit(errno);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno));
		exit(errno);
	}
	return (fd);
}

static bool	uncomplete_params(t_game *cub3d)
{
	if (cub3d->ready_for_map && cub3d->map)
		return (false);
	print_error(E_UPARAM);
	return (true);
}

static void	read_source_file(char *filename, t_game *cub3d)
{
	char	*line;
	int		fd;

	fd = open_source_file(filename);
	line = get_next_line(fd);
	while (line)
	{
		if (extract_params(&line, cub3d) == -1)
			break ;
		line = get_next_line(fd);
	}
	close(fd);
	test(cub3d);	// Prints game data;
	if (line || uncomplete_params(cub3d))
		clean_exit(cub3d, NULL, 2);
}

void	set_xpm_textures(t_game *cub3d)
{
	int	*h;
	int *w;

	h = calloc(1, sizeof(int));
	w = calloc(1, sizeof(int));
	*h = cub3d->xpm_images.height;
	*w = cub3d->xpm_images.width;
	cub3d->xpm_images.ea = mlx_xpm_file_to_image(cub3d->mlx.disp, cub3d->textures.ea, w, h);
	cub3d->xpm_images.we = mlx_xpm_file_to_image(cub3d->mlx.disp, cub3d->textures.we, &cub3d->xpm_images.width, &cub3d->xpm_images.height);
	cub3d->xpm_images.no = mlx_xpm_file_to_image(cub3d->mlx.disp, cub3d->textures.no, &cub3d->xpm_images.width, &cub3d->xpm_images.height);
	cub3d->xpm_images.so = mlx_xpm_file_to_image(cub3d->mlx.disp, cub3d->textures.so, &cub3d->xpm_images.width, &cub3d->xpm_images.height);

}

void	set_game_params(char *filename, t_game *cub3d)
{
	check_file_extension(filename);
	read_source_file(filename, cub3d);
	set_player(cub3d);
	validate_map(cub3d);
}
