/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:49:22 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 20:13:12 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_len;
	size_t	s1len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	total_len = s1len + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1len + 1);
	ft_strlcat(new_str, s2, total_len + 1);
	return (new_str);
}
