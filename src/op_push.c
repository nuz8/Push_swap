/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:01:42 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/14 07:15:43 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_stack(t_stack **receiver, t_stack **sender);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// Function to push an element from one stack to another
// void	push_stack(t_stack **receiver, t_stack **sender)
// {
// 	t_stack	*tmp1;
// 	t_stack	*tmp2;

// 	if (!(*sender))
// 		return ;
// 	if (!(*receiver))
// 	{
// 		tmp1 = *sender;
// 		tmp2 = *receiver;
// 		*sender = (*sender)->next;
// 		*receiver = tmp1;
// 		tmp1->next = tmp2;
// 		return ;
// 	}
// 	tmp1 = *sender;
// 	tmp2 = *receiver;
// 	*sender = (*sender)->next;
// 	*receiver = tmp1;
// 	tmp1->next = tmp2;
// }

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

// Function to push first element of stack a to stack b
// void	push_stack(t_stack **a, t_stack **b)
// {
// 	t_stack	*tmp;

// 	if (!(*a))
// 		return ;
// 	tmp = *a;
// 	*a = (*a)->next;
// 	tmp->next = *b;
// 	*b = tmp;
// }

void	pa(t_stack **a, t_stack **b)
{
	push_stack(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(a, b);
	// ft_putstr_fd("pb\n", 1);
	ft_putstr_fd("\t\t\t\tpb\n", 1);
}
