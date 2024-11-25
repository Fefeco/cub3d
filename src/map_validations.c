/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:10:24 by fcarranz          #+#    #+#             */
/*   Updated: 2024/11/25 12:42:41 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int ft_check_extension(const char *filename, const char *ext)
{
    int len_ext;
    int len_fname;

    if (!filename || !ext)
        return (-1);
    len_ext = ft_strlen(ext);
    len_fname = ft_strlen(filename);
    if (ft_strncmp(filename + (len_fname - len_ext), ext, len_ext))
        return (1);                                    
    return (0);
}
