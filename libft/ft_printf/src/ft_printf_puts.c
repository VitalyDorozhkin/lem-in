/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:57:42 by pmila             #+#    #+#             */
/*   Updated: 2019/10/16 19:57:52 by pmila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharf(char c)
{
	g_giter++;
	write(g_fd, &c, 1);
}

void	ft_putstrf(const char *s)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		g_giter += len;
		write(g_fd, s, len);
	}
}

void	ft_putcharsf(char c, int i)
{
	while (i-- > 0)
		ft_putcharf(c);
}
