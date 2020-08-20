/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:43:56 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/07 23:22:15 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;
	char	*ret;

	if (s == NULL)
		return (NULL);
	if (len == 0)
		return (ft_strnew(0));
	slen = ft_strlen(s);
	if (!(sub = ft_strnew(len)) || start > slen)
		return (NULL);
	ret = sub;
	s += start;
	while (len--)
	{
		*sub++ = *s++;
	}
	*sub = '\0';
	return (ret);
}
