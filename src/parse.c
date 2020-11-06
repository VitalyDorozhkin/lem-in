/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:11:13 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 14:11:16 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	ft_str_to_uint(t_lemin *lemin, const char *str)
{
	unsigned long long	res;

	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		res = res * 10 + *str - '0';
		if (res > 2147483647)
			ft_exit(lemin);
		str++;
	}
	return (res);
}

int	parse_room(t_lemin *lemin, char const *l, t_room **room)
{
	int		ret;
	char	**res;
	char	**res_ptr;

	ret = 0;
	if (!l || *l == '#' || *l == 'L' || !(res = ft_strsplit(l, ' ')))
		return (0);
	res_ptr = res;
	while (*res_ptr)
		res_ptr++;
	if (res_ptr - res == 3 && ft_str_to_uint(lemin, *(res + 1)) >= 0 &&
		ft_str_to_uint(lemin, *(res + 2)) >= 0 && (*room =
				(t_room *)ft_memalloc(sizeof(t_room))))
	{
		(*room)->name = *res;
		ft_memdel((void**)(res + (ret = 1)));
		ft_memdel((void**)(res + 2));
	}
	else if ((res_ptr = res))
		while (*res_ptr)
			ft_memdel((void**)res_ptr++);
	ft_memdel((void**)&res);
	if (!*room)
		ft_exit(lemin);
	return (ret);
}

int	parse_link(t_lemin *lemin, const char *l, t_link **link)
{
	int		ret;
	char	**res_ptr;
	char	**res;

	ret = 0;
	if (!l || *l == '#' || !(res = ft_strsplit(l, '-')))
		return (0);
	res_ptr = res;
	while (*res_ptr)
		res_ptr++;
	if (res_ptr - res == 2 && (*link = (t_link *)ft_memalloc(sizeof(t_link))))
	{
		(*link)->room1 = *res;
		(*link)->room2 = *(res + 1);
		(ret = 1);
	}
	else if ((res_ptr = res))
		while (*res_ptr)
			ft_memdel((void**)res_ptr++);
	ft_memdel((void**)&res);
	if (!*link)
		ft_exit(lemin);
	return (ret);
}

int	parse_line(t_lemin *lemin, const char *line, t_room **room, t_link **link)
{
	int	lemins;

	if (!line)
		ft_exit(lemin);
	if (*line == '#')
	{
		if (ft_strcmp(line + 1, "#start") == 0)
			return (-2);
		if (ft_strcmp(line + 1, "#end") == 0)
			return (-3);
	}
	else
	{
		lemins = ft_str_to_uint(lemin, line);
		if (lemins > 0)
			return (lemins);
		if (parse_room(lemin, line, room))
			return (-1);
		if (parse_link(lemin, line, link))
			return (-4);
		ft_exit(lemin);
	}
	return (0);
}
