/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:56:07 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:56:09 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_mem;

	if (!ptr)
		return (malloc(new_size));
	new_mem = malloc(new_size);
	ft_assert(new_mem != NULL, __FUNCTION__, "malloc error");
	ft_memcpy(new_mem, ptr, old_size < new_size ? old_size : new_size);
	free(ptr);
	return (new_mem);
}
