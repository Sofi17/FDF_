/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:45:28 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/13 15:12:49 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	char *ret;

	ret = str;
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (ret);
}
