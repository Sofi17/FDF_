/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:20:28 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/14 01:13:03 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t len;

	len = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		if (len + 1 == 0)
			return (0);
		lst = lst->next;
		len++;
	}
	return (len);
}
