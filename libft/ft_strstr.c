/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:39:05 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/07 17:36:40 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	need_len;
	char	*h;

	need_len = ft_strlen(needle);
	h = (char*)haystack;
	if (!needle)
		return (h);
	if (*needle == '\0' && *h == '\0')
		return (h);
	while (*h)
	{
		if (ft_strncmp(h, needle, need_len) == 0)
			return (h);
		h++;
	}
	return (NULL);
}
