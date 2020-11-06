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

int		free_g(void)
{
	if (g_fd != 1)
		close(g_fd);
	free(g_flags);
	return (g_giter);
}

int		ft_fprintf(char *file, const char *format, ...)
{
	va_list		argv;
	char		spec;

	g_iter = 0;
	g_giter = 0;
	g_fd = open(file, O_WRONLY);
	va_start(argv, format);
	if (!(g_flags = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (0);
	while (format[g_iter])
	{
		if (format[g_iter] != '%' || check_double_percents(format, 0))
			ft_putcharf(format[g_iter]);
		else
		{
			g_iter++;
			clear_flags();
			if (!(spec = read_flags(format, &argv, g_iter - 1)))
				continue ;
			choose_spec(spec, &argv);
		}
		g_iter++;
	}
	va_end(argv);
	return (free_g());
}
