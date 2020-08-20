/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:48:30 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/15 18:20:57 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*rew(char *str)
{
	while (ft_isdigit(*str) || *str == '-' || *str == '+')
		str++;
	return (str);
}

static double	ft_part(char *s)
{
	double	ret;
	double	i;

	ret = 0.0;
	i = 1;
	while (ft_isdigit(*s))
	{
		i *= 0.1;
		ret += (*s == '0') ? (0) : (i * (*s - '0'));
		s++;
	}
	return (ret);
}

static double	ft_integ(const char *str)
{
	double	res;

	res = 0.0;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10.0 + (*str - '0');
		str++;
	}
	return (res);
}

static double	ft_exp_dbl(double d, int e)
{
	while (e < 0)
	{
		d *= 0.1;
		e++;
	}
	while (e > 0)
	{
		d *= 10;
		e--;
	}
	return (d);
}

double			ft_atof(const char *str)
{
	double	a;
	double	b;
	int		e;
	int		sign;
	char	*s;

	if (str == NULL)
		return (0.0 / 0.0);
	b = 0.0;
	s = (char*)str;
	s = ft_strrew(s, ft_isspace);
	sign = (*s == '-') ? (-1) : (1);
	a = ft_integ(s);
	if (*(s = rew(s)) == '.')
		b = ft_part(++s);
	if (*(s = rew(s)) == 'e' || *s == 'E')
	{
		e = ft_atoi(++s);
		return (ft_exp_dbl(a + b, e) * sign);
	}
	if (ft_strcmpi(s, "inf") == 0)
		return (1.0 / 0.0 * sign);
	if (ft_strcmpi(s, "nan") == 0)
		return (0.0 / 0.0);
	return ((a + b) * sign);
}
