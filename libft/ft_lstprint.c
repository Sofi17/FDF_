/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:25:35 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/14 21:10:03 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *list, int isstr)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	i = 0;
	if (tmp == NULL)
		return ;
	ft_putendl("inx\tsize\tcontent");
	while (tmp != NULL)
	{
		ft_putnbr(i++);
		ft_putchar('\t');
		if (tmp->content_size == 0)
			ft_putendl("0\tnull");
		else
		{
			ft_putnbr(tmp->content_size);
			ft_putchar('\t');
			if (isstr)
				ft_putendl(tmp->content);
			else
				ft_putendl("*not str*");
		}
		tmp = tmp->next;
	}
}
