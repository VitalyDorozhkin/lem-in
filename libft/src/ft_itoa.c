/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:31:50 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 23:31:53 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	digit_capacity(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		r;

	i = digit_capacity(n);
	if (!(s = n <= 0 ? ft_strnew(++i) : ft_strnew(i)))
		return (NULL);
	s[0] = n < 0 ? '-' : '0';
	while (n != 0)
	{
		r = n < 0 ? -(n % 10) : n % 10;
		s[--i] = r + '0';
		n = n / 10;
	}
	return (s);
}
