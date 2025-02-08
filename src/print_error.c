/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:53:35 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/08 11:17:33 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "colors.h"
#include "libft.h"

void	print_error(const char *error, t_game *cub3d)
{
	if (!error || cub3d->has_print_error)
		return ;
	ft_putstr_fd(RED, 2);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(RESET, 2);
	cub3d->has_print_error = true;
}
