/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:31:40 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 12:31:42 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <b_tree.h>

t_btree	*btree_create_node(void *item)
{
	t_btree *tree;

	tree = (t_btree *)ft_memalloc(sizeof(t_btree));
	if (tree)
	{
		tree->item = item;
		tree->left = 0;
		tree->right = 0;
	}
	return (tree);
}

int		btree_insert_data(t_btree **root, void *item,
						int (*cmpf)(void *, void *))
{
	void	*t;
	int		diff;

	if (!*root)
	{
		*root = btree_create_node(item);
		return (0);
	}
	t = (*root)->item;
	diff = cmpf(t, item);
	if (diff == 0)
		return (1);
	if (diff > 0)
		return (btree_insert_data(&((*root)->left), item, cmpf));
	return (btree_insert_data(&((*root)->right), item, cmpf));
}

void	*btree_get_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	void	*t;
	int		diff;

	if (!*root)
		return (0);
	t = (*root)->item;
	diff = cmpf(t, item);
	if (diff == 0)
		return (t);
	if (diff > 0)
		return (btree_get_data(&((*root)->left), item, cmpf));
	return (btree_get_data(&((*root)->right), item, cmpf));
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

int		btree_items_count(t_btree *root)
{
	if (!root)
		return (0);
	return (btree_items_count(root->left) + btree_items_count(root->right) + 1);
}
