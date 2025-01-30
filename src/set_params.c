/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:56:05 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/30 17:52:41 by shurtado         ###   ########.fr       */
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
	test(cub3d);
	if (line || uncomplete_params(cub3d))
		clean_exit(cub3d, NULL, 2);
}

void	set_xpm_textures(t_game *cub3d)
{
	cub3d->xpm_images.ea = mlx_xpm_file_to_image(cub3d->mlx.disp, cub3d->textures.ea, &cub3d->xpm_images.width, &cub3d->xpm_images.height);
	cub3d->xpm_images.we = mlx_xpm_file_to_image(cub3d->mlx.disp, cub3d->textures.we, &cub3d->xpm_images.width, &cub3d->xpm_images.height);
	cub3d->xpm_images.no = mlx_xpm_file_to_image(cub3d->mlx.disp, cub3d->textures.no, &cub3d->xpm_images.width, &cub3d->xpm_images.height);
	cub3d->xpm_images.so = mlx_xpm_file_to_image(cub3d->mlx.disp, cub3d->textures.so, &cub3d->xpm_images.width, &cub3d->xpm_images.height);
	cub3d->xpm_images.ea->addr_to_draw = mlx_get_data_addr(cub3d->xpm_images.ea, &cub3d->xpm_images.ea->bits_per_pixel, &cub3d->xpm_images.ea->line_length, &cub3d->xpm_images.ea->endian);
	cub3d->xpm_images.we->addr_to_draw = mlx_get_data_addr(cub3d->xpm_images.we, &cub3d->xpm_images.we->bits_per_pixel, &cub3d->xpm_images.we->line_length, &cub3d->xpm_images.we->endian);
	cub3d->xpm_images.no->addr_to_draw = mlx_get_data_addr(cub3d->xpm_images.no, &cub3d->xpm_images.no->bits_per_pixel, &cub3d->xpm_images.no->line_length, &cub3d->xpm_images.no->endian);
	cub3d->xpm_images.so->addr_to_draw = mlx_get_data_addr(cub3d->xpm_images.so, &cub3d->xpm_images.so->bits_per_pixel, &cub3d->xpm_images.so->line_length, &cub3d->xpm_images.so->endian);
}

void	set_game_params(char *filename, t_game *cub3d)
{
	check_file_extension(filename);
	read_source_file(filename, cub3d);
	set_player(cub3d);
	validate_map(cub3d);
}
