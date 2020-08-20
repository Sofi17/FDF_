/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:08:57 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/09 16:19:33 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_two_bytes(int c, int fd)
{
	unsigned char o1;
	unsigned char o2;

	o1 = (unsigned char)((c >> 0x6) | 0xc0);
	o2 = (unsigned char)((c & 0x3f) | 0x80);
	write(fd, &o1, 1);
	write(fd, &o2, 1);
}

static void	put_three_bytes(int c, int fd)
{
	unsigned char o1;
	unsigned char o2;
	unsigned char o3;

	o1 = (unsigned char)((c >> 0xc) | 0xe0);
	o2 = (unsigned char)((c >> 0x6) | 0x80);
	o3 = (unsigned char)((c & 0x3f) | 0x80);
	write(fd, &o1, 1);
	write(fd, &o2, 1);
	write(fd, &o3, 1);
}

static void	put_four_bytes(int c, int fd)
{
	unsigned char o1;
	unsigned char o2;
	unsigned char o3;
	unsigned char o4;

	o1 = (unsigned char)((c >> 0x12) | 0xf0);
	o2 = (unsigned char)((c >> 0xc) | 0x80);
	o3 = (unsigned char)((c >> 0x6) | 0x80);
	o4 = (unsigned char)((c & 0x3f) | 0x80);
	write(fd, &o1, 1);
	write(fd, &o2, 1);
	write(fd, &o3, 1);
	write(fd, &o3, 1);
}

void		ft_put_unicode(int c, int fd)
{
	if (fd >= 0)
	{
		if (c >= 0 && c < 128)
			write(fd, &c, 1);
		else if (c > 127 && c < 2048)
			put_two_bytes(c, fd);
		else if (c > 2047 && c < 65536)
			put_three_bytes(c, fd);
		else if (c > 65535 && c < 1114112)
			put_four_bytes(c, fd);
	}
}
