/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:57:58 by pmila             #+#    #+#             */
/*   Updated: 2019/10/16 19:58:01 by pmila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(char *str, int flag)
{
	int		len;
	char	*s;

	if (!str)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(str);
	if (flag == 'r')
		s = ft_strrev(s);
	len = ft_strlen(s);
	if (g_flags->dote && len > g_flags->cut)
		len = g_flags->cut;
	if (g_flags->minus)
		write(1, s, len);
	ft_putcharsf(((!flag && (g_flags->zero && !g_flags->minus)) ? '0' : ' '),
			g_flags->min_width - len);
	if (!g_flags->minus)
		write(1, s, len);
	g_giter += len;
	ft_strdel(&s);
	return (0);
}
