/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:01:16 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 13:01:19 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	cmp_room(void *a, void *b)
{
	if (!a)
		return (1);
	if (!b)
		return (-1);
	return (ft_strcmp(((t_room *)a)->name, ((t_room *)b)->name));
}

int	cmp_path(void *a, void *b)
{
	if (!a)
		return (1);
	if (!b)
		return (-1);
	return ((t_path *)a)->len - ((t_path *)b)->len;
}

int	if_min(int *a, int b)
{
	if (a && b < *a)
	{
		*a = b;
		return (1);
	}
	return (0);
}

int	get_traffic(void *data)
{
	return ((t_path *)data)->len + ((t_path *)data)->lemins;
}
