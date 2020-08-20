/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getinx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:16:23 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/15 00:07:10 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_getinx(t_list *list, void *content, size_t size)
{
	int		inx;
	t_list	*tmp;

	if (list == NULL)
		return (-2);
	inx = 0;
	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->content == NULL)
		{
			if (content == NULL)
				return (inx);
		}
		else if (ft_memcmp(content, tmp->content, size) == 0)
			return (inx);
		inx++;
		tmp = tmp->next;
	}
	return (-1);
}
