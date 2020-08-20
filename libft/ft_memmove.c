/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:55:01 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:55:02 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	register unsigned char	*dest;
	register unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (dest == NULL && source == NULL)
		return (NULL);
	if (dest <= source)
		return (ft_memcpy(dst, src, len));
	else
	{
		dest += len;
		source += len;
		while (len >= 8)
		{
			dest -= 8;
			source -= 8;
			*((uint64_t*)dest) = *((uint64_t*)source);
			len -= 8;
		}
		while (len--)
			*(--dest) = *(--source);
	}
	return (dst);
}
