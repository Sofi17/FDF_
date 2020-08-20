/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:32:22 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/06 19:04:33 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if ((unsigned char*)dst == NULL && (unsigned char*)src == NULL)
		return (NULL);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n--)
	{
		if ((*d++ = *s++) == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
