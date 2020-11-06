/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:14:42 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 17:14:44 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_lemin	get_lemin(void)
{
	t_lemin	lemin;

	lemin.rooms_bt = 0;
	lemin.best_pathes = 0;
	lemin.lines = 0;
	lemin.start = 0;
	lemin.end = 0;
	lemin.rooms_ar = 0;
	return (lemin);
}

int		main_iteration(t_lemin *lemin, int *min)
{
	t_list2	*pathes;
	t_list2	*path;

	bf(lemin->rooms_ar);
	if (lemin->end->prev_from_all == 0 && lemin->end->prev_from_visited == 0)
		return (1);
	path = fill_next(lemin->end);
	process_new_links(path);
	list_clear(&path);
	ft_memdel((void**)&path);
	clear_rooms(lemin);
	pathes = get_all_pathes(lemin, lemin->start, lemin->end);
	if (if_min(min, launch_ants(pathes, lemin->lemins_count)))
	{
		list_apply(lemin->best_pathes, free_path);
		lst_free(&lemin->best_pathes);
		lemin->best_pathes = pathes;
	}
	else
	{
		list_apply(pathes, free_path);
		lst_free(&pathes);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_lemin	lemin;
	int		min;
	int		founded;

	founded = 0;
	lemin = get_lemin();
	min = 2000000000;
	main_validation(&lemin, 0, 0, 0b00011111u);
	while (!founded)
		founded = main_iteration(&lemin, &min);
	if (!lemin.best_pathes)
		ft_exit(&lemin);
	list_reverse(&lemin.lines);
	print_lines(lemin.lines);
	n();
	if (argc == 2 && !ft_strcmp(argv[1], "--show-traffic"))
		print_all_pathes(lemin.best_pathes);
	print_steps(lemin.best_pathes, min);
	free_lemin(&lemin);
	return (0);
}
