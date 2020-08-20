/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:27:34 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/07 20:35:12 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	if (size + 1 == 0)
		return (NULL);
	new = (char*)malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	ft_memset(new, '\0', size + 1);
	return (new);
}
