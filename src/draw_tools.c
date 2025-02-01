/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:48:06 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/01 11:13:51 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// Function to change
void	put_pxl_on_img(t_img *images, int x, int y, int color)
{
	char	*dst;

	dst = images->addr_to_draw + (y * images->line_length
			+ x * (images->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
// To
void	put_pxl_on_iimg(t_iimg *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_x_pxl / 8));
	*(unsigned int *)dst = color;
}
// End
