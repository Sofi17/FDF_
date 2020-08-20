/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:58:24 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:58:26 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uitoa_base(uint32_t value, char *buff, const int_fast16_t base,
		const int_fast16_t is_upper)
{
	static const char	digits[] = "0123456789abcdef0123456789ABCDEF";
	register char		*ptr;
	size_t				ret;

	ptr = buff;
	*ptr++ = digits[(value % base) + (is_upper != 0) * 16];
	value /= base;
	while (value != 0)
	{
		*ptr++ = digits[(value % base) + (is_upper != 0) * 16];
		value /= base;
	}
	ft_strrev(buff, ptr - 1);
	ret = ptr - buff;
	buff[ret] = 0;
	return (ret);
}
