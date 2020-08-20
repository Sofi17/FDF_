/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:53:22 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/07 17:40:29 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	need_len;
	char	*h;

	need_len = ft_strlen(needle);
	h = (char*)haystack;
	if (*needle == '\0')
		return (h);
	if (len == 0)
		return (NULL);
	if (*needle == '\0' && *h == '\0')
		return (h);
	while (len--)
	{
		if (need_len <= len + 1 && ft_strncmp(h, needle, need_len) == 0)
			return (h);
		if (*h == '\0')
			return (NULL);
		h++;
	}
	return (NULL);
}
