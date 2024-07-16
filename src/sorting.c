/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:57:23 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/16 08:39:34 by pamatya          ###   ########.fr       */
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
void	get_next_min(t_puswap *ps);
void	execute_rotation(t_puswap *ps, int *cost);

// Function to select and execute the sorting algorithm based on the size of the list
// void	start_sorting(t_stack **a, t_stack **b)
void	start_sorting(t_puswap *ps)
{
	ps->list_size = ft_stack_size(ps->a);
	ft_stack_minmax(ps);
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
	// int	minmax[2];

	elem[0] = ps->a->num;
	elem[1] = ps->a->next->num;
	elem[2] = ps->a->next->next->num;
	// ft_stack_minmax(ps->a, minmax);
	if (is_sorted(ps->a))
		return ;
	else if (ps->minmax[1] == elem[2])
		sa(ps);
	else if (ps->minmax[1] == elem[1] && ps->minmax[0] == elem[2])
		rra(ps);
	else if (ps->minmax[1] == elem[1] && ps->minmax[0] == elem[0])
	{
		rra(ps);
		sa(ps);
	}
	else if (ps->minmax[1] == elem[0] && ps->minmax[0] == elem[2])
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
	// int	new_min;															// This variable maybe used to store the value returned from a new function mentioned in the comments below.
	int	i;

	i = 0;
	while (i < (ps->list_size - 3))
	{
		// ft_stack_minmax(*a, minmax);											// I was here. I need to update minmax function to two separate functions because the new minimum value should be updated after each push, and the current function cannot do that since it is updating main's stack. And an array address cannot be returned from it as it will use it's own stack.
		if (ps->a->num != ps->minmax[0])
			get_next_min(ps);
		if (is_sorted(ps->a) && !(ps->b))
			return ;
		pb(ps);
		i++;
	}
	sort_three(ps);
	i = 0;
	while (i++ < (ps->list_size - 3))
		pa(ps);
}

// Function to rotate/shuffle the stack until the smallest number is at the top
// void	get_next_min(t_stack **a, int min)
void	get_next_min(t_puswap *ps)
{
	int	cost[2];
	int	i;
	
	cost[0] = 0;
	cost[1] = 0;
	i = 0;
	while (ps->a && ps->a->num != ps->minmax[0])
	{
		rotate_stack(&(ps->a));
		cost[0]++;
		i++;
	}
	while (i-- > 0)
		rev_rotate_stack(&(ps->a));
	i = 0;
	while (ps->a && ps->a->num != ps->minmax[0])
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
