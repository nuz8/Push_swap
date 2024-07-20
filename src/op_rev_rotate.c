/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:30 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/20 06:17:06 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate_stack(t_stack **root);
void	rra(t_puswap *ps);
void	rrb(t_puswap *ps);
void	rrr(t_puswap *ps);

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

void	rra(t_puswap *ps)
{
	rev_rotate_stack(&(ps->a));
	ft_putstr_fd("rra\n", 1);
	ps->total_moves++;
}

void	rrb(t_puswap *ps)
{
	rev_rotate_stack(&(ps->b));
	ft_putstr_fd("rrb\n", 1);
	ps->total_moves++;
}

void	rrr(t_puswap *ps)
{
	rev_rotate_stack(&(ps->a));
	rev_rotate_stack(&(ps->b));
	ft_putstr_fd("rrr\n", 1);
	ps->total_moves++;
}
