/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:24:28 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/15 07:38:41 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	index_list(t_stack **root, int list_size);
// void	index_list(t_stack **root, int *minmax, int list_size);
static t_stack	*get_nxtmin_node(t_stack *cur, int min, int new_max, int index);

// // Function to index the list from 0 to n by comparing each node with the smallest current node in the list
// void	index_list(t_stack **root, int *minmax, int list_size)
// {
// 	t_stack	*cur;
// 	t_stack	*nxtmin_node;
// 	int		new_max;
// 	int		index;
// 	int		curr_min;

// 	index = 0;
// 	while (index < list_size)
// 	{
// 		cur = *root;
// 		nxtmin_node = *root;
// 		new_max = minmax[1];
// 		while (cur)
// 		{
// 			if (index == 0 && cur->num == minmax[0])
// 				nxtmin_node = cur;
// 			else if (index > 0 && cur->num == (curr_min + 1))
// 			{
// 				nxtmin_node = cur;
// 				break ;
// 			}
// 			else if (index > 0 && cur->num > curr_min && cur->num <= new_max)
// 			{
// 				nxtmin_node = cur;
// 				new_max = cur->num;
// 			}
// 			cur = cur->next;
// 		}
// 		curr_min = nxtmin_node->num;
// 		nxtmin_node->index = index++;
// 	}
// }


static t_stack	*get_nxtmin_node(t_stack *cur, int min, int new_max, int index)
{
	t_stack	*nxtmin_node;
	
	while(cur)
	{
		if (index == 0 && cur->num == min)
			nxtmin_node = cur;
		else if (index > 0 && cur->num == (min + 1))
		{
			nxtmin_node = cur;
			break ;
		}
		else if (index > 0 && cur->num > min && cur->num <= new_max)
		{
			nxtmin_node = cur;
			new_max = cur->num;
		}
		cur = cur->next;
	}
	return (nxtmin_node);
}

// Function to index the list from 0 to n by comparing each node with the smallest current node in the list
// void	index_list(t_stack **root, int *minmax, int list_size)
void	index_list(t_stack **root, int list_size)
{
	t_stack	*cur;
	t_stack	*nxtmin_node;
	int		index;
	int		minmax[2];
	// int		curr_min;
	// int		new_max;

	index = 0;
	ft_stack_minmax(*root, minmax);
	// curr_min = minmax[0];
	while (index < list_size)
	{
		cur = *root;
		// new_max = minmax[1];
		// nxtmin_node = get_nxtmin_node(cur, curr_min, new_max, index);
		nxtmin_node = get_nxtmin_node(cur, minmax[0], minmax[1], index);
		// curr_min = nxtmin_node->num;
		minmax[0] = nxtmin_node->num;
		nxtmin_node->index = index++;
	}
}
