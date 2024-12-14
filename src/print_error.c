/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:53:35 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/14 22:28:27 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "colors.h"

void	print_error(const char *error)
{
	if (!error)
		return ;
	write(2, RED, 7);
	while (*error)
		write(2, error++, 1);
	write(2, "\n", 1);
	write(2, RESET, 7);
}
