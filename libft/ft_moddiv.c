/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moddiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:55:42 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:55:47 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_moddiv(const int32_t dividend, const int32_t divisor,
		int32_t *quotient)
{
	*quotient = dividend / divisor;
	return (dividend % divisor);
}
