/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:34:37 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/21 01:56:05 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		is_sorted(t_stack *root);
int		is_descending(t_stack *stk_b);
int		ft_stack_min(t_stack *root);
int		ft_stack_max(t_stack *root);

int	is_sorted(t_stack *root)
{
	t_stack	*cur;

	cur = root;
	while (cur && cur->next)
	{
		if (cur->num > cur->next->num)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	is_descending(t_stack *stk_b)
{
	t_stack	*cur;

	cur = stk_b;
	while (cur && cur->next)
	{
		if (cur->num < cur->next->num)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	ft_stack_min(t_stack *root)
{
	int	min;
	t_stack	*cur;

	min = root->num;
	cur = root;
	while (cur)
	{
		if (cur->num < min)
			min = cur->num;
		cur = cur->next;
	}
	return (min);
}

int	ft_stack_max(t_stack *root)
{
	int	max;
	t_stack	*cur;

	max = root->num;
	cur = root;
	while (cur)
	{
		if (cur->num > max)
			max = cur->num;
		cur = cur->next;
	}
	return (max);
}
