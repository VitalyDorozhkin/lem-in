/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pathes_with_ants.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:19:02 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 16:19:05 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		launch_ants(t_list2 *pathes, int ant)
{
	t_list2 *start;

	start = pathes;
	if (!pathes)
		return (-1);
	if (!pathes->next)
	{
		((t_path *)pathes->data)->lemins = ant;
		return (get_traffic(start->data) - 1);
	}
	while (ant)
	{
		((t_path *)pathes->data)->lemins += 1;
		ant--;
		if (get_traffic(pathes->data) <= get_traffic(pathes->next->data))
			pathes = start;
		else if ((pathes = pathes->next) && !pathes->next && ant)
		{
			((t_path *)pathes->data)->lemins += 1;
			ant--;
			pathes = start;
		}
	}
	return (get_traffic(start->data) - 1);
}

void	print_step(t_to_room *link)
{
	ft_putstr("L");
	ft_putnbr(link->to->lemin_cur);
	ft_putstr("-");
	ft_putstr(link->to->name);
}

void	step_to(t_to_room *link)
{
	link->to->lemin_cur = link->from->lemin_cur;
	link->from->lemin_cur = 0;
	print_step(link);
}

void	print_step_link(t_path *path, t_list2 *links, int *idx, int *any)
{
	t_to_room	*link;

	path->is_done = 1;
	links = path->path;
	while (links)
	{
		link = (t_to_room *)links->data;
		if (!links->next && path->lemins > 0)
		{
			(*idx)++;
			path->lemins--;
			link->from->lemin_cur = *idx;
		}
		if (link->from->lemin_cur)
		{
			if (*any)
				s();
			else
				*any = 1;
			step_to(link);
			path->is_done = 0;
		}
		links = links->next;
	}
}

void	print_steps(t_list2 *pathes, int steps)
{
	int			idx;
	int			any;
	t_list2		*path_list;
	t_path		*path;

	idx = 0;
	if (!pathes)
		return ;
	while (steps-- > 0)
	{
		path_list = pathes;
		any = 0;
		while (path_list)
		{
			path = (t_path *)path_list->data;
			if (!path->is_done)
				print_step_link(path, path->path, &idx, &any);
			path_list = path_list->next;
		}
		n();
	}
}
