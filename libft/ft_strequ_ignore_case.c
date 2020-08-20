/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ_ignore_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:27:06 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/07 22:31:55 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ_ignore_case(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (ft_tolower(*s1) == ft_tolower(*s2))
	{
		if (*s1 == 0)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}
