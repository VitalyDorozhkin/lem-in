/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:50:12 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 17:50:15 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	bf_visited(t_to_room *link, t_room *ptr, t_room *next, int *changes)
{
	int	w;

	if (link->reverse->status == 1)
	{
		w = (ptr)->min_distance_from_all + link->weight;
		if (if_min(&next->min_distance_from_visited, w))
		{
			next->prev_from_visited = link;
			if (if_min(&next->min_distance_from_all, w))
				next->prev_from_all = link;
			next->changed = 1;
			*changes = 1;
		}
	}
	else if ((ptr)->prev_from_visited)
	{
		w = (ptr)->min_distance_from_visited + link->weight;
		if (if_min(&next->min_distance_from_all, w))
		{
			next->prev_from_all = link;
			next->changed = 1;
			*changes = 1;
		}
	}
}

void	bf_room(t_room *ptr, t_list2 *list, int *changes)
{
	t_to_room	*link;
	t_room		*next;

	while ((ptr)->changed && list)
	{
		link = (t_to_room *)list->data;
		if (link->status == 0)
		{
			next = link->to;
			if (ptr->visited)
				bf_visited(link, ptr, next, changes);
			else if (if_min(&next->min_distance_from_all,
							(ptr)->min_distance_from_all + link->weight))
			{
				next->prev_from_all = link;
				next->changed = 1;
				*changes = 1;
			}
		}
		list = list->next;
	}
}

void	bf(t_room **rooms)
{
	t_room	**ptr;
	int		changes;

	changes = 1;
	while (changes)
	{
		changes = 0;
		ptr = rooms;
		while (*ptr)
		{
			bf_room(*ptr, (*ptr)->to_rooms, &changes);
			(*ptr)->changed = 0;
			ptr++;
		}
	}
}
