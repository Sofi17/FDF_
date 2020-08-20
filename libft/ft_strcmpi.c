/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 02:29:42 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/12 18:02:25 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmpi(char const *s1, char const *s2)
{
	int a1;
	int a2;

	while (*s1 && *s2)
	{
		a1 = ft_tolower(*s1);
		a2 = ft_tolower(*s2);
		if (a1 != a2)
			return (a1 - a2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
