/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:16:50 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 23:16:52 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <libft.h>

typedef struct	s_list2 {
	void			*data;
	struct s_list2	*next;
}				t_list2;

t_list2			*list_create_elem(void *data);
void			list_push_front(t_list2 **begin_list, void *data);
void			list_push_sort(t_list2 **begin_list, void *data,
				int (*cmpf)(void *, void *));
int				list_size(t_list2 *begin_list);
void			list_clear(t_list2 **begin_list);
void			list_reverse(t_list2 **begin_list);
void			lst_free(t_list2 **list);
void			list_apply(t_list2 *begin_list, void (*cmp)(void *));

#endif
