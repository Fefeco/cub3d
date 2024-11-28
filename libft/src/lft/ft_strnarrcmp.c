/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnarrcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:40:11 by fcarranz          #+#    #+#             */
/*   Updated: 2024/11/28 12:45:24 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnarrcmp(const char *s, const char **arr, size_t size)
{
	unsigned char	*str;
	unsigned char	**array;
	size_t			pos;

	if (!s || !arr)
		return (NULL);
	if (size == 0)
		size = ft_strlen(s) + 1;
	str = (unsigned char *)s;
	array = (unsigned char **)arr;
	while (*array)
	{
		pos = 0;
		while (*(str + pos) && *((*array) + pos) && (size - pos - 1))
		{
			if ((*(str + pos) - *((*array) + pos)) != 0)
				break ;
			++pos;
		}
		if (size - pos - 1 <= 1 && (*(str + pos) - *((*array) + pos) == 0))
			return ((char *)*array);
		++array;
	}
	return (NULL);
}
