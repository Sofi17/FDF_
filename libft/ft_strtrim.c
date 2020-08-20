/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:38:07 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/08 14:42:15 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trimlen(char const *s)
{
	size_t	len;

	len = ft_strlen(s);
	s += len - 1;
	while (len)
	{
		if (ft_isspace(*s))
			s--;
		else
			break ;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*trim;
	char	*ret;
	size_t	len;

	if (s == NULL)
		return (NULL);
	s = ft_strrew(s, ft_isspace);
	len = trimlen(s);
	trim = ft_strnew(len);
	if (!trim)
		return (NULL);
	ret = trim;
	while (len--)
		*trim++ = *s++;
	*trim = '\0';
	return (ret);
}
