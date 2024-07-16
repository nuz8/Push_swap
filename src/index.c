/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:24:28 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/16 07:11:19 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void			index_list(t_stack **root, int list_size);
void	index_list(t_puswap *ps);
t_stack	*get_nxtmin_node(t_stack *cur, int min, int new_max, int index);

void	index_list(t_puswap *ps)
{
	t_stack	*cur;
	t_stack	*nxtmin_node;
	int		index;
	// int		minmax[2];
	int		new_min;

	index = 0;
	new_min = ps->minmax[0];
	// ft_stack_minmax(*root, minmax);
	while (index < ps->list_size)
	{
		cur = ps->a;
		nxtmin_node = get_nxtmin_node(cur, new_min, ps->minmax[1], index);
		new_min = nxtmin_node->num;
		nxtmin_node->index = index++;
	}
}

t_stack	*get_nxtmin_node(t_stack *cur, int min, int new_max, int index)
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
