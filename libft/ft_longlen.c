/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:54:25 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:54:27 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_longlen(register int64_t n)
{
	register int64_t	rank;
	register size_t		i;

	if (n < 0)
	{
		if (n == INT64_MIN)
			return (19);
		else
			n = -n;
	}
	rank = 10;
	i = 1;
	while (i < 19)
	{
		if (n < rank)
			return (i);
		rank *= 10;
		i++;
	}
	return (19);
}
