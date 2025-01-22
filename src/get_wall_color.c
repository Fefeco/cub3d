/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:22:28 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/22 22:23:30 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_wall_color(double ray_dst)
{
    int t = 0; // Transparencia (0 = completamente opaco)
    int base_color = 255; // Blanco base (255 para R, G, y B)
    double factor = 1.0 / (1.0 + ray_dst * 0.1); // Factor de sombreado basado en la distancia

    // Atenuar los componentes RGB
    int r = (int)(base_color * factor);
    int g = (int)(base_color * factor);
    int b = (int)(base_color * factor);

    // Crear el color TRGB
    return create_trgb(t, r, g, b);
}
