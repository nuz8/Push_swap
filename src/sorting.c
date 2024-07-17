/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:57:23 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/17 05:26:23 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	start_sorting(t_stack **a, t_stack **b);
// void	sort_three(t_stack **a);
// void	sort_five(t_stack **a, t_stack **b, int list_size);
// void	get_next_min(t_stack **a, int min);
// void	execute_rotation(t_stack **a, int *cost);

void	start_sorting(t_puswap *ps);
void	sort_three(t_puswap *ps);
void	sort_five(t_puswap *ps);
void	get_next_min(t_puswap *ps, int new_min);
void	execute_rotation(t_puswap *ps, int *cost);

// Function to select and execute the sorting algorithm based on the size of the list
// void	start_sorting(t_stack **a, t_stack **b)
void	start_sorting(t_puswap *ps)
{
	ps->list_size = ft_stack_size(ps->a);
	// ft_stack_minmax(ps);
	ps->minmax[0] = ft_stack_min(ps->a);
	ps->minmax[1] = ft_stack_max(ps->a);
	index_list(ps);
	if (ps->list_size == 1)
		exit(0) ;
	else if (ps->list_size == 2)
		sa(ps);
	else if (ps->list_size == 3)
		sort_three(ps);
	else if (ps->list_size <= 5)
		sort_five(ps);
	else
		radix_sort(ps);
}

// Function to sort three numbers
// void	sort_three(t_stack **a);
void	sort_three(t_puswap *ps)
{
	int	elem[3];
	int	new_min;

	elem[0] = ps->a->num;
	elem[1] = ps->a->next->num;
	elem[2] = ps->a->next->next->num;
	new_min = ft_stack_min(ps->a);
	if (is_sorted(ps->a))
		return ;
	else if (ps->minmax[1] == elem[2])
		sa(ps);
	else if (ps->minmax[1] == elem[1] && new_min == elem[2])
		rra(ps);
	else if (ps->minmax[1] == elem[1] && new_min == elem[0])
	{
		rra(ps);
		sa(ps);
	}
	else if (ps->minmax[1] == elem[0] && new_min == elem[2])
	{
		ra(ps);
		sa(ps);
	}
	else
		ra(ps);
}

// Function to sort five numbers using sort_three function
// void	sort_five(t_stack **a, t_stack **b, int list_size);
void	sort_five(t_puswap *ps)
{
	int	new_min;
	int	i;
	// int	minmax[2];

	i = 0;
	while (i < 2)
	{
		new_min = ft_stack_min(ps->a);
		if (ps->a->num != ps->minmax[0])
			get_next_min(ps, new_min);
		// if (is_sorted(ps->a) && !(ps->b))
		if (is_sorted(ps->a) && ft_stack_size(ps->a) == ps->list_size)
			return ;
		pb(ps);
		i++;
	}
	// minmax[0] = ft_stack_min(ps->a);
	// minmax[1] = ft_stack_max(ps->a);
	sort_three(ps);
	// i = 0;
	// while (i++ < (ps->list_size - 3))
	while (i--)
		pa(ps);
}

// Function to rotate/shuffle the stack until the smallest number is at the top
// void	get_next_min(t_stack **a, int min)
void	get_next_min(t_puswap *ps, int new_min)
{
	int	cost[2];
	int	i;

	cost[0] = 0;
	cost[1] = 0;
	i = 0;
	while (ps->a && ps->a->num != new_min)
	{
		rotate_stack(&(ps->a));
		cost[0]++;
		i++;
	}
	while (i-- > 0)
		rev_rotate_stack(&(ps->a));
	i = 0;
	while (ps->a && ps->a->num != new_min)
	{
		rev_rotate_stack(&(ps->a));
		cost[1]++;
		i++;
	}
	while (i-- > 0)
		rotate_stack(&(ps->a));
	execute_rotation(ps, cost);
}

// Function to execute actual rotation based on total cost
// void	execute_rotation(t_stack **a, int *cost)
void	execute_rotation(t_puswap *ps, int *cost)
{
	int	i;
	
	i = 0;
	if (cost[0] <= cost[1])
	{
		i = cost[0];
		while (i-- > 0)
			ra(ps);
	}
	else
	{
		i = cost[1];
		while (i-- > 0)
			rra(ps);
	}
}
