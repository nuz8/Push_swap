/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:22 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/16 04:15:36 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	swap_stack(t_stack **root);
// void	sa(t_stack **a);
// void	sb(t_stack **b);
// void	ss(t_stack **a, t_stack **b);

void	swap_stack(t_stack **root);
void	sa(t_puswap *ps);
void	sb(t_puswap *ps);
void	ss(t_puswap *ps);

// Function to swap the first two elements of a stack
void	swap_stack(t_stack **root)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!(*root) || !((*root)->next))
		return ;
	tmp1 = *root;
	tmp2 = (*root)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*root = tmp2;
}

void	sa(t_puswap *ps)
{
	swap_stack(&(ps->a));
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_puswap *ps)
{
	swap_stack(&(ps->b));
	// ft_putstr_fd("sb\n", 1);
	ft_putstr_fd("\t\t\t\tsb\n", 1);
}

void	ss(t_puswap *ps)
{
	swap_stack(&(ps->a));
	swap_stack(&(ps->b));
	// ft_putstr_fd("ss\n", 1);
	ft_putstr_fd("\t\tss\n", 1);
}
