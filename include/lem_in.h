/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:09:59 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 23:10:02 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <b_tree.h>
# include <list.h>

typedef struct	s_path {
	int		lemins;
	int		len;
	int		is_done;
	t_list2	*path;
}				t_path;

typedef struct	s_to_room {
	int					weight;
	struct s_room		*from;
	struct s_room		*to;
	struct s_to_room	*reverse;
	int					status;
}				t_to_room;

typedef struct	s_room {
	int			idx;
	char		*name;
	int			visited;
	t_list2		*to_rooms;
	t_to_room	*next;
	t_to_room	*prev_from_visited;
	t_to_room	*prev_from_all;
	int			min_distance_from_visited;
	int			min_distance_from_all;
	int			lemin_cur;
	int			changed;
}				t_room;

typedef struct	s_link {
	char	*room1;
	char	*room2;
}				t_link;

typedef struct	s_lemin {
	int		room_count;
	int		lemins_count;
	t_btree	*rooms_bt;
	t_list2	*lines;
	t_list2	*best_pathes;
	t_room	**rooms_ar;
	t_room	*start;
	t_room	*end;
}				t_lemin;

void			mode_set_count(t_lemin *lemin, unsigned char *mode);
void			mode_check_room(t_lemin *lemin, unsigned char mode);
void			mode_check_no_task(t_lemin *lemin, unsigned char mode);
int				mode_task_start(unsigned char *mode);
int				mode_task_end(unsigned char *mode);
void			mode_set_start(t_lemin *lemin, unsigned char *mode);
void			mode_set_end(t_lemin *lemin, unsigned char *mode);
int				mode_set_link(t_lemin *lemin, unsigned char *mode);
void			mode_check_fill(t_lemin *lemin, unsigned char mode);
int				parse_line(t_lemin *lemin, const char *line, t_room **room,
					t_link **link);
void			tree_to_room_array(t_btree *root, t_room **arr, int *index);
int				get_traffic(void *data);
void			ft_exit(t_lemin *lemin);
int				launch_ants(t_list2 *pathes, int ant);
void			n();
void			s();
void			print_all_pathes(t_list2 *path_list);
void			print_steps(t_list2 *pathes, int steps);
void			print_lines(t_list2 *lines);
void			process_new_links(t_list2 *links);
t_list2			*fill_next(t_room *to);
void			clear_rooms(t_lemin *lemin);
t_list2			*get_all_pathes(t_lemin *lemin, t_room *start, t_room *end);
int				cmp_room(void *a, void *b);
int				cmp_path(void *a, void *b);
int				if_min(int *a, int b);
void			free_lemin(t_lemin *lemin);
void			free_path(void *data);
void			free_room(void *data);
void			fill_rooms_array_in_lemin(t_lemin *lemin);
void			fill_rooms_links_in_lemin(t_lemin *l, t_link **cur_link,
					t_to_room *r1, t_to_room *r2);
void			bf(t_room **rooms);
void			main_validation(t_lemin *lemin, t_room *cur_room,
					t_link *cur_link, unsigned char mode);
#endif
