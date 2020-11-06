/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:54:26 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 13:54:33 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	mode_set_count(t_lemin *lemin, unsigned char *mode)
{
	if (!mode)
		return ;
	if (*mode == 0b00011111u)
		*mode = 0b00001111u;
	else
		ft_exit(lemin);
}

void	mode_set_start(t_lemin *lemin, unsigned char *mode)
{
	if (!mode)
		return ;
	if ((*mode & 0b11111101u) == 0b00001101u)
		*mode = 0b00101101u | (*mode & 0b00000010u);
	else
		ft_exit(lemin);
}

void	mode_set_end(t_lemin *lemin, unsigned char *mode)
{
	if (!mode)
		return ;
	if ((*mode & 0b11111011u) == 0b00001011u)
		*mode = 0b00011011u | (*mode & 0b00000100u);
	else
		ft_exit(lemin);
}

int		mode_set_link(t_lemin *lemin, unsigned char *mode)
{
	if (!mode)
		return (0);
	if (*mode == 0b00001001u)
	{
		*mode = 0b00000001u;
		return (1);
	}
	if (*mode != 0b00000001u)
		ft_exit(lemin);
	return (0);
}
