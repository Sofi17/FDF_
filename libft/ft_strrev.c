/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:58:03 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:58:05 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(register char *begin, register char *end)
{
	register char	tmp;

	while (end > begin)
	{
		tmp = *end;
		*end-- = *begin;
		*begin++ = tmp;
	}
}
