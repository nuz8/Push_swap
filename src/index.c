/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:24:28 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/15 06:48:02 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	index_list(t_stack **root);
void	index_list(t_stack **root, int *minmax, int list_size);

// // Function to index the list from 0 to n by comparing each node with the smallest current node in the list
// void	index_list(t_stack **root, int *minmax, int list_size)
// {
// 	t_stack	*cur;
// 	t_stack	*nxt_min;
// 	int		new_max;
// 	int		index;
// 	int		curr_min;

// 	index = 0;
// 	while (index < list_size)
// 	{
// 		cur = *root;
// 		nxt_min = *root;
// 		new_max = minmax[1];
// 		while (cur)
// 		{
// 			if (index == 0 && cur->num == minmax[0])
// 				nxt_min = cur;
// 			else if (index > 0 && cur->num == (curr_min + 1))
// 			{
// 				nxt_min = cur;
// 				break ;
// 			}
// 			else if (index > 0 && cur->num > curr_min && cur->num <= new_max)
// 			{
// 				nxt_min = cur;
// 				new_max = cur->num;
// 			}
// 			cur = cur->next;
// 		}
// 		curr_min = nxt_min->num;
// 		nxt_min->index = index++;
// 	}
// }

// Function to index the list from 0 to n by comparing each node with the smallest current node in the list
void	index_list(t_stack **root, int *minmax, int list_size)
{
	t_stack	*cur;
	t_stack	*nxt_min;
	int		new_max;
	int		index;
	int		curr_min;

	index = 0;
	while (index < list_size)
	{
		cur = *root;
		nxt_min = *root;
		new_max = minmax[1];
		while (cur)
		{
			if (index == 0 && cur->num == minmax[0])
				nxt_min = cur;
			else if (index > 0 && cur->num == (curr_min + 1))
			{
				nxt_min = cur;
				break ;
			}
			else if (index > 0 && cur->num > curr_min && cur->num <= new_max)
			{
				nxt_min = cur;
				new_max = cur->num;
			}
			cur = cur->next;
		}
		curr_min = nxt_min->num;
		nxt_min->index = index++;
	}
}
