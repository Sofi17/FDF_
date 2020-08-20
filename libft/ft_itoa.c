/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:09:38 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/09 00:24:16 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(int n)
{
	size_t len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*ret;
	char	*s;
	long	nn;

	len = intlen(n);
	if (!(s = ft_strnew(len)))
		return (NULL);
	ret = s;
	nn = n;
	if (nn == 0)
		*s = 48;
	else if (nn < 0)
	{
		*s = '-';
		nn *= -1;
	}
	s += len;
	while (nn)
	{
		*(--s) = nn % 10 + 48;
		nn /= 10;
	}
	return (ret);
}
