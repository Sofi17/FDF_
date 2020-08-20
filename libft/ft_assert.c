/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:52:17 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:52:19 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

/*
**	call examples:
**	ft_assert(i < MAX_LEN, __FUNCTION__, "going beyond the array");
**
**	ft_assert(a->length + shift < FLT_MAX_LEN, __FUNCTION__,
**	"too long float or too much shift - out of array");
*/

void	ft_assert(int_fast32_t to_check, const char *func, const char *message)
{
	if (!to_check)
	{
		ft_log_error(message, "ASSERTION", func, NULL);
		exit(SIGABRT);
	}
}
