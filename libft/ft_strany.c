/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strany.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:56:22 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:56:24 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strany(char const *str, const int32_t c)
{
	if (str == NULL)
		return (0);
	if ((unsigned char)c == '\0')
		return (1);
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (1);
		str++;
	}
	return (0);
}
