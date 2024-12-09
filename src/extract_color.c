/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:49:23 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/09 12:48:30 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static int	check_color(t_color *rgb)
{
	if (!rgb)
		return (-1);
	if (rgb->red == -1 || rgb->green == -1 || rgb->blue == -1)
		return (print_err("Wrong color format", -1));
	return (0);
}

static int	color_is_set(const t_color *rgb)
{
	if (rgb->red != -1 || rgb->green != -1 || rgb->blue != -1)
		return (print_err("Too many declarations for color parameter", -1));
	return (0);
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

int	get_color(const char **line)
{
	char	*octet;
	int		pos;

	if (!**line)
		return (-1);
	octet = (char *)calloc(4, sizeof(char));
	if (!octet)
		return (print_err("Malloc failed!", -1));
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
		return (print_err("Instruction not allowed in map file", -1));
	if (*line++ == 'F')
		rgb = &cub3d->floor;
	else
		rgb = &cub3d->ceiling;
	if (color_is_set(rgb))
		return (-1);
	rgb->red = get_color(&line);
	rgb->green = get_color(&line);
	rgb->blue = get_color(&line);
	return (check_color(rgb));
}
