/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:42:28 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:31:05 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *s, char c)
{
	size_t	words;

	words = 0;
	if (!s || *s == '\0')
		return (0);
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			words++;
		s++;
	}
	return (words);
}

static size_t	next_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			len++;
			break ;
		}
		if (*s != c)
			len++;
		s++;
	}
	return (len);
}

static char		**free_tab(char **split)
{
	while (*split)
	{
		free(*split);
		split++;
	}
	free(split);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	char	**ret;
	size_t	len;

	if (!s || !(split = malloc(sizeof(char*) * (words_count(s, c) + 1))))
		return (NULL);
	ret = split;
	while (*s)
	{
		if (*s != c && *s != '\0')
		{
			len = next_len(s, c);
			if ((*split = ft_strnew(len)) == NULL)
				return (free_tab(ret));
			ft_memcpy(*split, s, len);
			s += (len - 1);
			split++;
		}
		s++;
	}
	*split = NULL;
	return (ret);
}
