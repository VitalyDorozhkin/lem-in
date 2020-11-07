/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_bf_path_processing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:00:59 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 19:01:01 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			check_room_visited(t_list2 *links)
{
	while (links)
	{
		if (((t_to_room *)links->data)->status == 1)
			return (1);
		links = links->next;
	}
	return (0);
}

void		process_new_links(t_list2 *links)
{
	int			i;
	t_to_room	*link;

	i = 0;
	while (links)
		if ((link = (t_to_room *)links->data) && link->reverse->status == 1)
		{
			link->reverse->status = 0;
			link->status = 0;
			link->reverse->weight = 1;
			link->weight = 1;
			link->to->visited = check_room_visited(link->to->to_rooms);
			link->from->visited = check_room_visited(link->from->to_rooms);
			links = links->next;
		}
		else
		{
			link->reverse->weight = link->reverse->weight * -1;
			if (i)
				link->from->visited = 1;
			else
				i = 1;
			link->status = 1;
			links = links->next;
		}
}

t_list2		*fill_next(t_room *to)
{
	t_list2	*res;
	int		next_visited;

	res = 0;
	next_visited = 0;
	while (to->prev_from_all || to->prev_from_visited)
	{
		if (!next_visited && to->visited)
		{
			to->prev_from_visited->from->next = to->prev_from_visited;
			list_push_front(&res, (void *)(to->prev_from_visited));
			next_visited = to->visited;
			to = to->prev_from_visited->from;
		}
		else
		{
			to->prev_from_all->from->next = to->prev_from_all;
			list_push_front(&res, (void *)(to->prev_from_all));
			next_visited = to->visited;
			to = to->prev_from_all->from;
		}
	}
	return (res);
}

void		clear_room(void *data)
{
	t_room	*room;

	room = (t_room*)data;
	if (!data)
		return ;
	room->min_distance_from_all = 2147483640;
	room->min_distance_from_visited = 2147483640;
	room->prev_from_all = 0;
	room->prev_from_visited = 0;
	room->next = 0;
	room->changed = 0;
}

void		clear_rooms(t_lemin *lemin)
{
	btree_apply_prefix(lemin->rooms_bt, clear_room);
	lemin->start->min_distance_from_all = 0;
	lemin->start->min_distance_from_visited = 0;
	lemin->start->changed = 1;
}
