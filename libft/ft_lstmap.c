/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:27:15 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/12 18:01:23 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*delete_list(t_list *list)
{
	t_list *next;

	if (list == NULL)
		return (NULL);
	while (list)
	{
		next = list->next;
		if (list->content != NULL)
			free(list->content);
		free(list);
		list = next;
	}
	list = NULL;
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *head;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(list = f(lst)))
		return (NULL);
	head = list;
	lst = lst->next;
	while (lst)
	{
		if (!(list->next = f(lst)))
			return (delete_list(head));
		list = list->next;
		lst = lst->next;
	}
	return (head);
}
