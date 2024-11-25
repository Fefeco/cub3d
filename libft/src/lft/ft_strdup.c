/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:35:51 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 20:03:48 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dst;

	len = ft_strlen((char *)str) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (dst)
		ft_strlcpy(dst, str, len);
	return (dst);
}
