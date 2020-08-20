/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:59:42 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:59:43 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(const wint_t *s)
{
	register size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len++;
		len += *s > 0xFFFF;
		len += *s > 0x7FF;
		len += *s > 0x7F;
		++s;
	}
	return (len);
}
