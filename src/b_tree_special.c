/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:45:58 by pparalax          #+#    #+#             */
/*   Updated: 2020/11/04 12:46:02 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <b_tree.h>
#include <lem_in.h>

void	tree_to_room_array(t_btree *root, t_room **arr, int *index)
{
	t_room	*room;

	if (!root)
		return ;
	if (root->left)
		tree_to_room_array(root->left, arr, index);
	room = (t_room*)root->item;
	room->idx = *index;
	arr[*index] = (t_room *)root->item;
	*index = *index + 1;
	if (root->right)
		tree_to_room_array(root->right, arr, index);
}

void	btree_free(t_btree *root)
{
	if (!root)
		return ;
	if (root->left)
	{
		btree_free(root->left);
		ft_memdel((void**)&root->left);
		root->left = 0;
	}
	if (root->right)
	{
		btree_free(root->right);
		ft_memdel((void**)&root->right);
		root->left = 0;
	}
}
