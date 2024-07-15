/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:24:28 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/15 21:14:09 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			index_list(t_stack **root, int list_size);
static t_stack	*get_nxtmin_node(t_stack *cur, int min, int new_max, int index);

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

void	index_list(t_stack **root, int list_size)
{
	t_stack	*cur;
	t_stack	*nxtmin_node;
	int		index;
	int		minmax[2];

	index = 0;
	ft_stack_minmax(*root, minmax);
	while (index < list_size)
	{
		cur = *root;
		nxtmin_node = get_nxtmin_node(cur, minmax[0], minmax[1], index);
		minmax[0] = nxtmin_node->num;
		nxtmin_node->index = index++;
	}
}
