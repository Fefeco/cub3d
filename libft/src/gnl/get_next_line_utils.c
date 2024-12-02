/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:36:56 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/02 13:30:33 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*ft_get_newl_ptr(const char *str)
{
	if (!str)
		return (NULL);
	while (*str && *str != '\n')
		++str;
	if (*str)
		return ((char *)str);
	return (NULL);
}
