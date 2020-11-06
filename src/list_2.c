/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:32:54 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 23:32:56 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	list_apply(t_list2 *begin_list, void (*cmp)(void *))
{
	while (begin_list)
	{
		(*cmp)(begin_list->data);
		begin_list = begin_list->next;
	}
}

void	list_push_sort(t_list2 **begin_list, void *data,
						int (*cmpf)(void *, void *))
{
	t_list2	*i;

	if (begin_list)
	{
		if (*begin_list == 0)
			*begin_list = list_create_elem(data);
		else if (cmpf((*begin_list)->data, data) >= 0)
			list_push_front(begin_list, data);
		else
		{
			i = (*begin_list);
			while (i->next != NULL && cmpf(i->next->data, data) <= 0)
				i = i->next;
			list_push_front(&i->next, data);
		}
	}
}

void	list_reverse(t_list2 **begin_list)
{
	t_list2	*tmp;
	t_list2	*tmp2;
	t_list2	*list;

	if (!begin_list)
		return ;
	list = *begin_list;
	if (list == 0 || list->next == 0)
		return ;
	tmp = list->next;
	tmp2 = tmp->next;
	list->next = 0;
	tmp->next = list;
	while (tmp2)
	{
		list = tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
		tmp->next = list;
	}
	*begin_list = tmp;
}
