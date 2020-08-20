/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:53:00 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:53:02 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t elem_size)
{
	register void	*ptr;
	register size_t full_size;

	if ((full_size = n_elem * elem_size) == 0)
		full_size = 1;
	ptr = malloc(full_size);
	ft_assert(ptr != NULL, __FUNCTION__, "malloc error");
	ft_bzero(ptr, full_size);
	return (ptr);
}
