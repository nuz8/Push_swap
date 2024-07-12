/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:30 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/12 23:39:35 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate_stack(t_stack **root);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// Function to reverse rotate a stack
void	rev_rotate_stack(t_stack **root)
{
	t_stack *scnd_last;
	t_stack	*last;

	if (!(*root) || !((*root)->next))
		return ;
	last = ft_stack_last(*root);
	scnd_last = *root;
	while (scnd_last->next != last)
		scnd_last = scnd_last->next;
	scnd_last->next = NULL;
	last->next = *root;
	*root = last;
}

void	rra(t_stack **a)
{
	rev_rotate_stack(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	rev_rotate_stack(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	ft_putstr_fd("rrr\n", 1);
}
