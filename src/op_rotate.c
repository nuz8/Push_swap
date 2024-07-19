/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/19 09:23:50 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	rotate_stack(t_stack **root);
// void	ra(t_stack **a);
// void	rb(t_stack **b);
// void	rr(t_stack **a, t_stack **b);

void	rotate_stack(t_stack **root);
void	ra(t_puswap *ps);
void	rb(t_puswap *ps);
void	rr(t_puswap *ps);

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

void	ra(t_puswap *ps)
{
	rotate_stack(&(ps->a));
	ft_putstr_fd("ra\n", 1);
	ps->total_moves++;
	print_stacks(ps);
}

void	rb(t_puswap *ps)
{
	rotate_stack(&(ps->b));
	ft_putstr_fd("rb\n", 1);
	// ft_putstr_fd("\t\t\t\trb\n", 1);
	ps->total_moves++;
	print_stacks(ps);
}

void	rr(t_puswap *ps)
{
	rotate_stack(&(ps->a));
	rotate_stack(&(ps->b));
	ft_putstr_fd("rr\n", 1);
	// ft_putstr_fd("\t\trr\n", 1);
	ps->total_moves++;
	print_stacks(ps);
}
