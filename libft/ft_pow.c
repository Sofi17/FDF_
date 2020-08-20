/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:55:56 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:55:58 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(const double base, register int_fast16_t power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (ft_pow(1 / base, -power));
	if (power & 1)
		return (base * ft_pow(base, power - 1));
	return (ft_pow(base * base, power / 2));
}
