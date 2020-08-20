/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:09:38 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:31:50 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_log_error(const char *message, const char *cause, const char *func,
		const char *file)
{
	write(2, "ERROR ", 6);
	if (message)
		write(2, message, ft_strlen(message));
	else
		write(2, "*null*", 6);
	if (cause)
	{
		write(2, ", CAUSE: ", 9);
		write(2, cause, ft_strlen(cause));
	}
	if (func)
	{
		write(2, ", FUNCTION: ", 12);
		write(2, func, ft_strlen(func));
	}
	if (file)
	{
		write(2, ", FILE: ", 8);
		write(2, file, ft_strlen(file));
	}
	write(2, "\n", 1);
}
