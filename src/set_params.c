/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:56:05 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/31 13:41:28 by fcarranz         ###   ########.fr       */
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
	t_tex	*tex;
	void	*disp;

	tex = &cub3d->tex;
	disp = cub3d->mlx.disp;
	tex->img_ea = mlx_xpm_file_to_image(disp, tex->file_ea, &tex->w, &tex->h);
	tex->img_we = mlx_xpm_file_to_image(disp, tex->file_we, &tex->w, &tex->h);
	tex->img_no = mlx_xpm_file_to_image(disp, tex->file_no, &tex->w, &tex->h);
	tex->img_so = mlx_xpm_file_to_image(disp, tex->file_so, &tex->w, &tex->h);
	tex->img_ea->addr_to_draw = mlx_get_data_addr(tex->img_ea,
			&tex->img_ea->bits_per_pixel, &tex->img_ea->line_length,
			&tex->img_ea->endian);
	tex->img_we->addr_to_draw = mlx_get_data_addr(tex->img_we,
			&tex->img_we->bits_per_pixel, &tex->img_we->line_length,
			&tex->img_we->endian);
	tex->img_no->addr_to_draw = mlx_get_data_addr(tex->img_no,
			&tex->img_no->bits_per_pixel, &tex->img_no->line_length,
			&tex->img_no->endian);
	tex->img_so->addr_to_draw = mlx_get_data_addr(tex->img_so,
			&tex->img_so->bits_per_pixel, &tex->img_so->line_length,
			&tex->img_so->endian);
}

void	set_game_params(char *filename, t_game *cub3d)
{
	check_file_extension(filename);
	read_source_file(filename, cub3d);
	set_player(cub3d);
	validate_map(cub3d);
}
