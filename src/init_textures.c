/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:00:24 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 11:05:21 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "cub3d.h"

static void	init_with_height(t_tex *tex)
{
	tex->w = 64;
	tex->h = 64;
}

void	init_textures(t_game *cub3d)
{
	t_tex	*tex;

	tex = &cub3d->no;
	tex->file = NULL;
	init_image(&tex->data);
	init_with_height(tex);
	tex = &cub3d->so;
	tex->file = NULL;
	init_image(&tex->data);
	init_with_height(tex);
	tex = &cub3d->ea;
	tex->file = NULL;
	init_image(&tex->data);
	init_with_height(tex);
	tex = &cub3d->we;
	tex->file = NULL;
	init_image(&tex->data);
	init_with_height(tex);
}
