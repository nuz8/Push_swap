/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:15:49 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/16 01:26:59 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix_sort(t_stack **a, t_stack **b, int list_size);
int		get_bits(int list_size);


// void	check_with_rotations(t_stack **a)
// {
	
// }

// void	check_with_swap(t_stack **a)
// {
	
// }

// Simple radix implementation
void	radix_sort(t_stack **a, t_stack **b, int list_size)
{
	int	bits;
	int	list;
	int	i;
	
	bits = get_bits(list_size);
	i = 0;
	while (i < bits)
	{
		list = list_size;
		while (list)
		{
			if (((*a)->index) & (1 << i))
				ra(a);
			else
				pb(a, b);
			list--;
			if (is_sorted(a))
				break;
		}
		while (*b)
			pa(a, b);
		i++;
		// if (!*b && is_sorted(a))
		// 	return ;
	}
}

int		get_bits(int list_size)
{
	int		bits;

	bits = 0;
	while (list_size > 0)
	{
		list_size = list_size / 2;
		bits++;
	}
	return (bits);
}
