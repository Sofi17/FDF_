/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:53:18 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:53:20 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_divmod(const int32_t dividend, const int32_t divisor,
		int32_t *remainder)
{
	*remainder = dividend % divisor;
	return (dividend / divisor);
}
