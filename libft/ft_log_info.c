/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:09:38 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/09 00:24:16 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_log_info(const char *message, const char *desc, const char *func,
		const char *file)
{
	write(1, "INFO ", 5);
	if (message)
		write(1, message, ft_strlen(message));
	else
		write(1, "*null*", 6);
	if (desc)
	{
		write(1, ", DESC: ", 8);
		write(1, desc, ft_strlen(func));
	}
	if (func)
	{
		write(1, ", FUNCTION: ", 12);
		write(1, func, ft_strlen(func));
	}
	if (file)
	{
		write(1, ", FILE: ", 8);
		write(1, file, ft_strlen(file));
	}
	write(1, "\n", 1);
}
