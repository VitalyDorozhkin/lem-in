/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:52:44 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 13:52:47 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	mode_check_room(t_lemin *lemin, unsigned char mode)
{
	if (!(mode & 0b0001000u))
		ft_exit(lemin);
}

void	mode_check_no_task(t_lemin *lemin, unsigned char mode)
{
	if (mode & 0b11100000u)
		ft_exit(lemin);
}

int		mode_task_start(unsigned char *mode)
{
	if (!mode)
		return (0);
	if ((*mode & 0b11111101u) == 0b00101101u)
	{
		*mode = 0b00001001u | (*mode & 0b00000010u);
		return (1);
	}
	return (0);
}

int		mode_task_end(unsigned char *mode)
{
	if (!mode)
		return (0);
	if ((*mode & 0b11111011u) == 0b00011011u)
	{
		*mode = 0b00001001u | (*mode & 0b00000100u);
		return (1);
	}
	return (0);
}

void	mode_check_fill(t_lemin *lemin, unsigned char mode)
{
	if (mode != 0b00000001u)
		ft_exit(lemin);
}
