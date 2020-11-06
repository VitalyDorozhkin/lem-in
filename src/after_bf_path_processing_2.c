/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_bf_path_processing_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:11:27 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 21:11:29 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_to_room	*get_next_blocked_to_room(t_list2 *links)
{
	t_to_room	*link;

	while (links)
	{
		link = (t_to_room *)links->data;
		if (link->status == 1)
			return (link);
		links = links->next;
	}
	return (0);
}

t_path		*get_normal_path(t_to_room *link_from_start, t_room *end)
{
	t_path		*res;
	t_room		*room;
	t_to_room	*link;

	if (!(res = (t_path*)ft_memalloc(sizeof(t_path))))
		return (0);
	res->is_done = 0;
	res->lemins = 0;
	if (!link_from_start)
		return (0);
	list_push_front(&res->path, (void *)link_from_start);
	room = link_from_start->to;
	while (room != end)
	{
		link = get_next_blocked_to_room(room->to_rooms);
		list_push_front(&res->path, (void *)link);
		room = link->to;
	}
	res->len = list_size(res->path);
	return (res);
}

t_list2		*get_all_pathes(t_lemin *lemin, t_room *start, t_room *end)
{
	t_list2	*path_list;
	t_path	*path;
	t_list2	*ptr;

	ptr = start->to_rooms;
	path_list = 0;
	while (ptr && ptr->data)
	{
		if (((t_to_room *)ptr->data)->status == 1)
		{
			if (!(path = get_normal_path((t_to_room *)ptr->data, end)))
			{
				list_apply(path_list, free_path);
				lst_free(&path_list);
				ft_exit(lemin);
			}
			list_push_sort(&path_list, (void *)path, cmp_path);
		}
		ptr = ptr->next;
	}
	return (path_list);
}
