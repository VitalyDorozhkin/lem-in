/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:15:18 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 20:15:20 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	n(void)
{
	ft_putstr("\n");
}

void	s(void)
{
	ft_putstr(" ");
}

void	print_path(t_list2 *path)
{
	t_to_room	*link;
	t_list2		*path_tmp;

	list_reverse(&path);
	path_tmp = path;
	if (path_tmp)
	{
		link = (t_to_room *)path_tmp->data;
		ft_printf("[%2s]", link->from->name);
	}
	while (path_tmp)
	{
		link = (t_to_room *)path_tmp->data;
		ft_printf("->[%2s]", link->to->name);
		path_tmp = path_tmp->next;
	}
	list_reverse(&path);
}

void	print_all_pathes(t_list2 *path_list)
{
	while (path_list)
	{
		ft_printf("%-5d", ((t_path *)path_list->data)->lemins);
		print_path(((t_path *)path_list->data)->path);
		n();
		path_list = path_list->next;
	}
	n();
}

void	print_lines(t_list2 *lines)
{
	while (lines)
	{
		ft_putendl(lines->data);
		lines = lines->next;
	}
}
