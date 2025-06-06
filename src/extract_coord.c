/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:24:18 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/08 11:14:04 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static char	*rm_spaces_endl(const char *str)
{
	char	*tmp;
	char	*ret;

	tmp = ft_rmspaces(str);
	if (!tmp)
		return (NULL);
	ret = ft_strtrim(tmp, "\n");
	free (tmp);
	return (ret);
}

void	set_xpm_texture(t_game *cub3d, t_tex *tex)
{
	void	*disp;

	disp = cub3d->mlx.disp;
	if (!disp || !tex)
		return ;
	tex->data.img = mlx_xpm_file_to_image(disp, tex->file, &tex->w, &tex->h);
	if (!tex->data.img)
	{
		print_error(E_MLXIMG, cub3d);
		return ;
	}
	tex->data.addr = mlx_get_data_addr(tex->data.img, &tex->data.bits_x_pxl,
			&tex->data.line_len, &tex->data.endian);
}

static t_tex	*get_texture(const char *id, t_game *cub3d)
{
	if (!ft_strncmp(id, "NO", 3))
		return (&cub3d->no);
	else if (!ft_strncmp(id, "SO", 3))
		return (&cub3d->so);
	else if (!ft_strncmp(id, "EA", 3))
		return (&cub3d->ea);
	else if (!ft_strncmp(id, "WE", 3))
		return (&cub3d->we);
	else
		return (NULL);
}

static bool	set_coord(char *tmp, const char *line, t_game *cub3d,
		char *ref_line)
{
	t_tex	*tex;
	char	*value;

	tex = get_texture(tmp, cub3d);
	if (!tex)
		return (false);
	value = rm_spaces_endl(line);
	if (!value)
		return (false);
	if (tex->file)
	{
		free (value);
		free (ref_line);
		free (tmp);
		clean_exit(cub3d, E_TMCOOR, 99);
	}
	if (!file_access(value, cub3d))
	{
		free (value);
		return (false);
	}
	tex->file = value;
	set_xpm_texture(cub3d, tex);
	return (true);
}

int	extract_coord(const char *line, t_game *cub3d, char *ref_line)
{
	char		*tmp;
	bool		success;
	const char	*coords[] = {"NO", "SO", "WE", "EA", NULL};

	tmp = (char *)ft_calloc(3, sizeof(char));
	if (!tmp)
	{
		print_error(E_MALLOC, cub3d);
		return (-1);
	}
	success = false;
	tmp[0] = *line++;
	while (*line && (ft_isspace(*line) || *line == '\n'))
		++line;
	if (*line)
	{
		tmp[1] = *line++;
		if (*line && ft_isspace(*line) && ft_strnarrcmp(tmp, coords, 3))
			success = set_coord(tmp, line, cub3d, ref_line);
	}
	free (tmp);
	if (success)
		return (0);
	print_error(E_WINST, cub3d);
	return (-1);
}
