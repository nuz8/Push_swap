/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/20 06:15:37 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_stack(t_stack **root);
void	ra(t_puswap *ps);
void	rb(t_puswap *ps);
void	rr(t_puswap *ps);

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
}

void	rb(t_puswap *ps)
{
	rotate_stack(&(ps->b));
	ft_putstr_fd("rb\n", 1);
	ps->total_moves++;
}

void	rr(t_puswap *ps)
{
	rotate_stack(&(ps->a));
	rotate_stack(&(ps->b));
	ft_putstr_fd("rr\n", 1);
	ps->total_moves++;
}
