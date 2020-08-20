/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_pow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:54:12 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:54:14 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_long_pow(const long double base, register int_fast16_t power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (ft_long_pow(1 / base, -power));
	if (power & 1)
		return (base * ft_long_pow(base, power - 1));
	return (ft_long_pow(base * base, power / 2));
}
