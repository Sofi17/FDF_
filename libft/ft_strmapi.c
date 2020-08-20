/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:19:23 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/07 22:24:57 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	char			*ret;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	map = ft_strnew(ft_strlen(s));
	if (!map)
		return (NULL);
	ret = map;
	i = 0;
	while (*s)
	{
		*map = f(i, *s);
		map++;
		s++;
		i++;
	}
	return (ret);
}
