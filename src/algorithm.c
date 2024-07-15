/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:57:23 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/14 23:54:41 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	start_sorting(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b, int list_size);
void	get_next_min(t_stack **a, int min);
void	execute_rotation(t_stack **a, int *cost);

// Function to select and execute the sorting algorithm based on the size of the list
void	start_sorting(t_stack **a, t_stack **b)
{
	int		list_size;

	list_size = ft_stack_size(*a);
	if (list_size == 1)
		exit(0) ;
	else if (list_size == 2)
		sa(a);	
	else if (list_size == 3)
		sort_three(a);
	else if (list_size <= 5)
		sort_five(a, b, list_size);
	// else
	// 	radix_sort(a, b, list_size);
}

// Function to sort three numbers
void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;
	int	minmax[2];

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	ft_stack_minmax(*a, minmax);
	if (minmax[1] == third)
		sa(a);
	else if (minmax[1] == second && minmax[0] == third)
		rra(a);
	else if (minmax[1] == second && minmax[0] == first)
	{
		rra(a);
		sa(a);
	}
	else if (minmax[1] == first && minmax[0] == third)
	{
		ra(a);
		sa(a);
	}
	else
		ra(a);
}

// Function to sort five numbers using sort_three function
void	sort_five(t_stack **a, t_stack **b, int list_size)
{
	int	minmax[2];
	int	i;

	i = 0;
	while (i < (list_size - 3))
	{
		ft_stack_minmax(*a, minmax);
		if ((*a)->num != minmax[0])
			get_next_min(a, minmax[0]);
		pb(a, b);
		i++;
	}
	sort_three(a);
	i = 0;
	while (i++ < (list_size - 3))
		pa(a, b);
}

// Function to rotate/shuffle the stack until the smallest number is at the top
void	get_next_min(t_stack **a, int min)
{
	int	cost[2];
	int	i;
	
	cost[0] = 0;
	cost[1] = 0;
	i = 0;
	while (*a && (*a)->num != min)
	{
		rotate_stack(a);
		cost[0]++;
		i++;
	}
	while (i-- > 0)
		rev_rotate_stack(a);
	i = 0;
	while (*a && (*a)->num != min)
	{
		rev_rotate_stack(a);
		cost[1]++;
		i++;
	}
	while (i-- > 0)
		rotate_stack(a);
	execute_rotation(a, cost);
}

// Function to execute actual rotation based on total cost
void	execute_rotation(t_stack **a, int *cost)
{
	int	i;
	
	i = 0;
	if (cost[0] <= cost[1])
	{
		i = cost[0];
		while (i-- > 0)
			ra(a);
	}
	else
	{
		i = cost[1];
		while (i-- > 0)
			rra(a);
	}
}
