/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:30:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/14 14:02:56 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end_ptr;
	char		*new_str;

	end_ptr = s1 + ft_strlen(s1);
	while (ft_strchr(set, *s1) && s1 < end_ptr)
		++s1;
	while (ft_strchr(set, *(end_ptr - 1)) && end_ptr > s1)
		--end_ptr;
	new_str = (char *)malloc(sizeof(char) * (end_ptr - s1 + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, (end_ptr - s1 + 1));
	return (new_str);
}
