/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:50:10 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 18:18:17 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int c, size_t len)
{
	unsigned char	u_c;
	unsigned char	*ptr;

	u_c = (unsigned char)c;
	ptr = (unsigned char *)buffer;
	while (len--)
		*ptr++ = u_c;
	return (buffer);
}
