/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelinx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:31:12 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/15 16:34:16 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelinx(t_list **alst, int inx, void (*del)(void*, size_t))
{
	t_list	*prev;
	t_list	*curr;
	int		i;

	if (*alst == NULL || inx < 0 || inx + 1 > (int)ft_lstlen(*alst))
		return ;
	if (ft_lstlen(*alst) == 1 || inx == 0)
	{
		ft_lstdelone(alst, del);
		return ;
	}
	prev = *alst;
	curr = (*alst)->next;
	i = 1;
	while (curr)
	{
		if (i++ == inx)
		{
			prev->next = curr->next;
			ft_lstdelone(&curr, del);
			return ;
		}
		prev = prev->next;
		curr = curr->next;
	}
}
