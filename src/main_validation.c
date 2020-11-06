/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:12:57 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 21:12:59 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	fill_rooms_array_in_lemin(t_lemin *lemin)
{
	int	idx;

	idx = 0;
	lemin->room_count = btree_items_count(lemin->rooms_bt);
	lemin->rooms_ar = (t_room **)ft_memalloc(
			(sizeof(t_room *) * (lemin->room_count + 1)));
	if (!lemin->rooms_ar)
		ft_exit(lemin);
	tree_to_room_array(lemin->rooms_bt, lemin->rooms_ar, &idx);
}

void	fill_rooms_links_in_lemin(t_lemin *l, t_link **cur_link, t_to_room *r1,
							t_to_room *r2)
{
	t_room		r;

	r1 = (t_to_room *)ft_memalloc(sizeof(t_to_room));
	r2 = (t_to_room *)ft_memalloc(sizeof(t_to_room));
	if (r1 && r2)
	{
		r.name = (*cur_link)->room1;
		r1->to = (t_room *)btree_get_data(&l->rooms_bt, (void *)&r, cmp_room);
		r.name = (*cur_link)->room2;
		r1->from = (t_room *)btree_get_data(&l->rooms_bt, (void *)&r, cmp_room);
	}
	ft_memdel((void**)&(*cur_link)->room1);
	ft_memdel((void**)&(*cur_link)->room2);
	ft_memdel((void**)cur_link);
	if (!r1 || !r2 || !r1->to || !r1->from)
		ft_exit(l);
	r2->to = r1->from;
	r2->from = r1->to;
	r1->weight = 1;
	r2->weight = 1;
	r1->reverse = r2;
	r2->reverse = r1;
	list_push_front(&r1->to->to_rooms, (void *)r2);
	list_push_front(&r2->to->to_rooms, (void *)r1);
}

void	main_validation_room(t_lemin *lemin, unsigned char *mode,
							t_room *cur_room)
{
	mode_check_room(lemin, *mode);
	cur_room->min_distance_from_all = 2000000000;
	cur_room->min_distance_from_visited = 2000000000;
	if (mode_task_start(mode))
	{
		cur_room->min_distance_from_all = 0;
		cur_room->min_distance_from_visited = 0;
		cur_room->changed = 1;
		lemin->start = cur_room;
	}
	if (mode_task_end(mode))
		lemin->end = cur_room;
	if (btree_insert_data(&lemin->rooms_bt, cur_room, cmp_room) != 0)
		ft_exit(lemin);
}

void	main_validation(t_lemin *lemin, t_room *cur_room, t_link *cur_link,
						unsigned char mode)
{
	char	*line;
	int		res;

	while (!(line = 0) && get_next_line(0, &line))
	{
		list_push_front(&lemin->lines, line);
		res = parse_line(lemin, line, &cur_room, &cur_link);
		if (res > 0 && (lemin->lemins_count = res))
			mode_set_count(lemin, &mode);
		else if (res == 0)
			mode_check_no_task(lemin, mode);
		else if (res == -1)
			main_validation_room(lemin, &mode, cur_room);
		else if (res == -2)
			mode_set_start(lemin, &mode);
		else if (res == -3)
			mode_set_end(lemin, &mode);
		else if (res == -4)
		{
			if (mode_set_link(lemin, &mode))
				fill_rooms_array_in_lemin(lemin);
			fill_rooms_links_in_lemin(lemin, &cur_link, 0, 0);
		}
	}
	mode_check_fill(lemin, mode);
}
