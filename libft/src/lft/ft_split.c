/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:14:59 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 19:40:13 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free_arrays(char **array, size_t i)
{
	while (i != 0)
		free(array[--i]);
	return (0);
}

static int	ft_fill_array(char **array, const char *str, char c)
{
	size_t	len;
	size_t	index;

	index = 0;
	while (*str)
	{
		len = 0;
		while (*str && *str == c)
			++str;
		while (*str && *str != c)
		{
			++len;
			++str;
		}
		if (len > 0)
		{
			array[index] = (char *)malloc(sizeof(char) * (len + 1));
			if (!array[index])
				return (ft_free_arrays(array, index));
			ft_strlcpy(array[index], str - len, len + 1);
			++index;
		}
	}
	return (1);
}

static size_t	ft_count_str(char const *str, char c)
{
	size_t	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c)
			++str;
		if (*str)
			++count;
		while (*str && *str != c)
			++str;
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	size_t	str_amount;
	char	**array;

	str_amount = ft_count_str(str, c);
	array = malloc(sizeof(char *) * (str_amount + 1));
	if (!array)
		return (NULL);
	array[str_amount] = NULL;
	if (ft_fill_array(array, str, c))
		return (array);
	free (array);
	return (NULL);
}
