/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:19:24 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 23:19:25 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_TREE_H
# define B_TREE_H

# include <libft.h>

typedef struct	s_btree {
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

t_btree			*btree_create_node(void *item);
int				btree_insert_data(t_btree **root, void *item,
				int (*cmpf)(void *, void *));
void			*btree_get_data(t_btree **root, void *item,
				int (*cmpf)(void *, void *));
void			btree_apply_prefix(t_btree *root, void (*applyf)(void *));
int				btree_items_count(t_btree *root);
void			btree_free(t_btree *root);
#endif
