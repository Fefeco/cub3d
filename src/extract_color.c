/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:49:23 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/08 11:12:04 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

bool	color_ok(t_color *color)
{
	if (color->red < 0 || color->red > 255)
		return (false);
	if (color->green < 0 || color->green > 255)
		return (false);
	if (color->blue < 0 || color->blue > 255)
		return (false);
	return (true);
}

static int	char_rgb_to_int(char **octet)
{
	int	tmp;

	if (**octet)
		tmp = ft_atoi(*octet);
	if (!**octet || tmp < 0 || tmp > 255)
		tmp = -1;
	free (*octet);
	*octet = NULL;
	return (tmp);
}

int	get_color(const char **line, t_game *cub3d)
{
	char	*octet;
	int		pos;

	if (!**line)
		return (-1);
	octet = (char *)calloc(4, sizeof(char));
	if (!octet)
	{
		print_error(E_MALLOC, cub3d);
		return (-1);
	}
	pos = 0;
	while (**line && **line != ',' && **line != '\n')
	{
		if (ft_isdigit(**line))
			octet[pos++] = **line;
		else if (!ft_isspace(**line) || pos == 4)
		{
			free(octet);
			return (-1);
		}
		++*line;
	}
	++*line;
	return (char_rgb_to_int(&octet));
}

int	extract_color(const char *line, t_game *cub3d)
{
	t_color	*rgb;

	if (!ft_isspace(*(line + 1)))
	{
		print_error(E_WINST, cub3d);
		return (-1);
	}
	if (*line++ == 'F')
		rgb = &cub3d->floor;
	else
		rgb = &cub3d->ceiling;
	if (color_ok(rgb))
	{
		print_error(E_TMCOL, cub3d);
		return (-1);
	}
	rgb->red = get_color(&line, cub3d);
	rgb->green = get_color(&line, cub3d);
	rgb->blue = get_color(&line, cub3d);
	if (color_ok(rgb) == false)
	{
		print_error(E_WCOLOR, cub3d);
		return (-1);
	}
	return (0);
}
