/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:15:49 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/20 07:05:43 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		radix_sort(t_puswap *ps);
void		sort_bit(t_puswap *ps, int *list, int bit);
int			get_bits(int list_size);
void		check_swap_rotate(t_puswap *ps);
static void	check_rotate(t_puswap *ps, int swap_toggle);

// // Radix1: Simple radix implementation
// // void	radix_sort(t_stack **a, t_stack **b, int list_size)
// void	radix_sort(t_puswap *ps)
// {
// 	int	bits;
// 	int	list;
// 	int	i;

// 	bits = get_bits(ps->list_size);
// 	i = 0;
// 	// check_swap_rotate(ps);
// 	while (i < bits)
// 	{
// 		list = ps->list_size;
// 		while (list)
// 		{
// 			if ((ps->a->index) & ft_power(2, i))
// 				ra(ps);
// 			else
// 				pb(ps);
// 			list--;
// 			if (is_sorted(ps->a))
// 				break;
// 			// pre_optimizers(ps, list);
// 		}
// 		while (ps->b)
// 			pa(ps);
// 		i++;
// 		// if (!*b && is_sorted(a))
// 		// 	return ;
// 	}
// }

// Radix2: Radix implementation with smart push based on no. of elements left in each stack
void	radix_sort(t_puswap *ps)
{
	int	bits;
	int	list[2];
	int	bit;

	bits = get_bits(ps->list_size);
	bit = 0;
	check_swap_rotate(ps);
	while (bit < bits)
	{
		list[0] = ft_stack_size(ps->a);
		list[1] = ft_stack_size(ps->b);
		sort_bit(ps, list, bit);
		bit++;
		if (bit == bits || ft_stack_size(ps->a) >= ft_stack_size(ps->b))
			while (ps->b)
				pa(ps);
		else
			while (ps->a)
				pb(ps);
	}
}

// Extension of radix_sort function
void	sort_bit(t_puswap *ps, int *list, int bit)
{
	while (list[0] || list[1])
	{
		if (list[0])
		{
			if ((ps->a->index) & ft_power(2, bit))
				ra(ps);
			else
				pb(ps);
			list[0]--;
			if (is_sorted(ps->a))
				break;
		}
		else if (list[1])
		{
			if ((ps->b->index) & ft_power(2, bit))
				pa(ps);
			else
				rb(ps);
			list[1]--;
			if (is_descending(ps->b))
				break;
		}
		if (is_sorted(ps->a) && is_descending(ps->b))
			break ;
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

// void	check_swap_rotate(t_puswap *ps)
// {
// 	int	swap_toggle;
// 	int	count;

// 	swap_toggle = 0;
// 	if (ps->a->index > ps->a->next->index)
// 	{
// 		swap_stack(&(ps->a));
// 		if (is_sorted(ps->a))
// 			frexit(1, "sa\n", ps, NULL, 0);
// 		swap_toggle = 1;
// 	}
// 	count = 0;
// 	while (ps->a->index != 0)
// 	{
// 		rotate_stack(&(ps->a));
// 		count++;
// 	}
// 	if (is_sorted(ps->a))
// 	{
// 		if (swap_toggle)
// 			ft_putstr_fd("sa\n", 1);
// 		while (count--)
// 			ft_putstr_fd("ra\n", 1);
// 		frexit(1, NULL, ps, NULL, 0);
// 	}
// 	while (count--)
// 		rev_rotate_stack(&(ps->a));
// 	if (swap_toggle)
// 		swap_stack(&(ps->a));
// }

void	check_swap_rotate(t_puswap *ps)
{
	int	swap_toggle;

	swap_toggle = 0;
	if (ps->a->index > ps->a->next->index)
	{
		swap_stack(&(ps->a));
		if (is_sorted(ps->a))
			frexit(1, "sa\n", ps, NULL, 0);
		swap_toggle = 1;
	}
	check_rotate(ps, swap_toggle);
	if (swap_toggle)
		swap_stack(&(ps->a));
}

// Extension of check_swap_rotate function
static void	check_rotate(t_puswap *ps, int swap_toggle)
{
	int	count;
	
	count = 0;
	while (ps->a->index != 0)
	{
		rotate_stack(&(ps->a));
		count++;
	}
	if (is_sorted(ps->a))
	{
		if (swap_toggle)
			ft_putstr_fd("sa\n", 1);
		while (count--)
			ft_putstr_fd("ra\n", 1);
		frexit(1, NULL, ps, NULL, 0);
	}
	while (count--)
		rev_rotate_stack(&(ps->a));
}
