/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_count                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:42:28 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:31:05 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_words_count(char const *s, char delimiter)
{
	size_t	words;

	words = 0;
	if (!s || *s == '\0')
		return (0);
	while (*s)
	{
		if (*s != delimiter && (*(s + 1) == delimiter || *(s + 1) == '\0'))
			words++;
		s++;
	}
	return (words);
}
