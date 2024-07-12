/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/12 23:40:39 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_stack(t_stack **root);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// Function to rotate a stack
void	rotate_stack(t_stack **root)
{
	t_stack *first;
	t_stack	*last;

	if (!(*root) || !((*root)->next))
		return ;
	first = *root;
	last = ft_stack_last(*root);
	*root = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate_stack(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate_stack(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putstr_fd("rr\n", 1);
}
