/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:20:40 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/06 21:29:50 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;

	dst_len = ft_strnlen(dst, size);
	if (dst_len == size)
		return (size + ft_strlen(src));
	return (dst_len + ft_strlcpy(dst + dst_len, src, size - dst_len));
}
