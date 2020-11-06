/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:47:29 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 12:47:33 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	free_room(void *data)
{
	t_room	*room;

	room = (t_room*)data;
	list_apply(room->to_rooms, free);
	list_clear(&room->to_rooms);
	ft_memdel((void**)&room->name);
	ft_memdel((void**)&room);
}

void	free_path(void *data)
{
	t_path	*path;

	path = (t_path*)data;
	list_clear(&path->path);
	ft_memdel((void**)&path->path);
	ft_memdel((void**)&path);
}

void	free_lines(t_list2 *lines)
{
	t_list2	*tmp;

	while (lines)
	{
		tmp = lines;
		lines = lines->next;
		ft_memdel((void**)&tmp->data);
		ft_memdel((void**)&tmp);
	}
}

void	free_lemin(t_lemin *lemin)
{
	ft_memdel((void**)&lemin->rooms_ar);
	free_lines(lemin->lines);
	btree_apply_prefix(lemin->rooms_bt, free_room);
	btree_free(lemin->rooms_bt);
	ft_memdel((void**)&lemin->rooms_bt);
	list_apply(lemin->best_pathes, free_path);
	list_clear(&lemin->best_pathes);
	ft_memdel((void**)&lemin->best_pathes);
}
