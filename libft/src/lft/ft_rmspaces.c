/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmspaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:09:45 by fcarranz          #+#    #+#             */
/*   Updated: 2024/11/28 14:48:04 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_no_space_chars(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
			++len;
		++str;
	}
	return (len);
}

char	*ft_rmspaces(const char	*src)
{
	char	*dst;
	int		pos;
	size_t	len;

	if (!src)
		return (NULL);
	len = count_no_space_chars(src);
	if (!len)
		return (NULL);
	dst = (char *)calloc((len + 1), sizeof(char));
	if (!dst)
		return (NULL);
	pos = 0;
	while (*src)
	{
		if (!ft_isspace(*src))
			dst[pos++] = *src;
		++src;
	}
	return (dst);
}
