/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:01:42 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/20 06:14:15 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_stack(t_stack **receiver, t_stack **sender);
void	pa(t_puswap *ps);
void	pb(t_puswap *ps);

void	push_stack(t_stack **sender, t_stack **receiver)
{
	t_stack	*tmp;

	if (!(*sender))
		return ;
	tmp = *sender;
	*sender = (*sender)->next;
	tmp->next = *receiver;
	*receiver = tmp;
}

void	pa(t_puswap *ps)
{
	push_stack(&(ps->b), &(ps->a));
	ft_putstr_fd("pa\n", 1);
	ps->total_moves++;
}

void	pb(t_puswap *ps)
{
	push_stack(&(ps->a), &(ps->b));
	ft_putstr_fd("pb\n", 1);
	ps->total_moves++;
}
