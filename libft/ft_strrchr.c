/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:48:35 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/07 17:28:01 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	tmp = (char*)s;
	i = ft_strlen(tmp);
	tmp += i;
	while (i + 1)
	{
		if ((unsigned char)*tmp == (unsigned char)c)
			return (tmp);
		tmp--;
		i--;
	}
	return (NULL);
}
