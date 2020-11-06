/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:30:44 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 13:30:49 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list2	*list_create_elem(void *data)
{
	t_list2	*l;

	if (!(l = (t_list2 *)ft_memalloc(sizeof(t_list2))))
		return (0);
	l->data = data;
	l->next = 0;
	return (l);
}

void	list_push_front(t_list2 **begin_list, void *data)
{
	t_list2	*node;

	if (*begin_list == NULL)
	{
		*begin_list = list_create_elem(data);
		(*begin_list)->next = 0;
	}
	else
	{
		node = list_create_elem(data);
		(*node).next = (*begin_list);
		*begin_list = node;
	}
}

void	lst_free(t_list2 **alst)
{
	t_list2	*tmp;
	t_list2	*next;

	if (!alst)
		return ;
	tmp = *alst;
	while (tmp)
	{
		next = tmp->next;
		ft_memdel((void**)&tmp);
		tmp = next;
	}
	*alst = 0;
}

int		list_size(t_list2 *begin_list)
{
	int		size;
	t_list2	*i;

	size = 0;
	i = begin_list;
	while (i)
	{
		++size;
		i = i->next;
	}
	return (size);
}

void	list_clear(t_list2 **begin_list)
{
	if (!begin_list)
		return ;
	if (*begin_list && (*begin_list)->next)
		list_clear(&(*begin_list)->next);
	ft_memdel((void**)begin_list);
	*begin_list = 0;
}
