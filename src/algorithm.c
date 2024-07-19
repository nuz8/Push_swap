/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:15:49 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/19 04:18:13 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	radix_sort(t_stack **a, t_stack **b, int list_size);
// int		get_bits(int list_size);

void	radix_sort(t_puswap *ps);
int		get_bits(int list_size);
int		ft_power(int base, int exp);
void	pre_optimizers(t_puswap *ps, int remaining);
// void	post_optimizers(t_puswap *ps, int remaining);

void	check_swap_rotate(t_puswap *ps)
{
	int	scount;
	int	count;

	scount = 0;
	if (ps->a->index > ps->a->next->index)
	{
		swap_stack(&(ps->a));
		if (is_sorted(ps->a))
		{
			ft_putstr_fd("sa\n", 1);
			frexit(NULL, ps, NULL, 5);
		}
		scount = 1;
	}
	count = 0;
	while (ps->a->index != 0)
	{
		rotate_stack(&(ps->a));
		count++;
	}
	if (is_sorted(ps->a))
	{
		if (scount)
			ft_putstr_fd("sa\n", 1);
		while (count--)
			ft_putstr_fd("ra\n", 1);
		frexit(NULL, ps, NULL, 6);
	}
	while (count--)
		rev_rotate_stack(&(ps->a));
	if (scount)
		swap_stack(&(ps->a));
}

// Radix1: Simple radix implementation
// void	radix_sort(t_stack **a, t_stack **b, int list_size)
void	radix_sort(t_puswap *ps)
{
	int	bits;
	int	list;
	int	i;

	bits = get_bits(ps->list_size);
	i = 0;
	// check_swap_rotate(ps);													// I was here. Need debug and check for this input as using this function somehow doesn't work for this input: 8 9 10 1 2 3 4 5 6 7
	while (i < bits)															// Checked this, and it was because the count, if swap was made, was not toggled (with scount). Fixed it with scount = 1 if swap is made (in the check_swap_rotate function).
	{
		list = ps->list_size;
		while (list)
		{
			if ((ps->a->index) & ft_power(2, i))
				ra(ps);
			else
				pb(ps);
			list--;
			if (is_sorted(ps->a))
				break;
			// pre_optimizers(ps, list);
		}
		while (ps->b)
			pa(ps);
		i++;
		// if (!*b && is_sorted(a))
		// 	return ;
	}
}

// // Radix2: Radix implementation with smart push based on no. of elements left in each stack
// // void	radix_sort(t_stack **a, t_stack **b, int list_size)
// void	radix_sort(t_puswap *ps)
// {
// 	int	bits;
// 	int	list[2];
// 	int	i;

// 	bits = get_bits(ps->list_size);
// 	i = 0;
// 	check_swap_rotate(ps);
// 	while (i < bits)
// 	{
// 		list[0] = ft_stack_size(ps->a);
// 		list[1] = ft_stack_size(ps->b);
// 		while (list[0] || list[1])
// 		{
// 			if (list[0])
// 			{
// 				if ((ps->a->index) & ft_power(2, i))
// 					ra(ps);
// 				else
// 					pb(ps);
// 				list[0]--;
// 				if (is_sorted(ps->a))
// 					break;
// 			}
// 			else if (list[1])
// 			{
// 				if ((ps->b->index) & ft_power(2, i))
// 					pa(ps);
// 				else
// 					rb(ps);
// 				list[1]--;
// 				if (is_descending(ps->b))
// 					break;
// 			}
// 			if (is_sorted(ps->a) && is_descending(ps->b))
// 				break ;
// 		}
// 		i++;
// 		if (i == bits || ft_stack_size(ps->a) >= ft_stack_size(ps->b))
// 			while (ps->b)
// 				pa(ps);
// 		else
// 			while (ps->a)
// 				pb(ps);
// 	}
// }

// // Radix3: Radix implementation with smart push based on no. of elements left in each stack
// // void	radix_sort(t_stack **a, t_stack **b, int list_size)
// void	radix_sort(t_puswap *ps)
// {
// 	int	bits;
// 	int	list[2];
// 	int	i;

// 	bits = get_bits(ps->list_size);
// 	i = 0;
// 	check_swap_rotate(ps);
// 	while (i < bits)
// 	{
// 		list[0] = ft_stack_size(ps->a);
// 		list[1] = ft_stack_size(ps->b);
// 		while (list[0] || list[1])
// 		{
// 			if (list[0])
// 			{
// 				if ((ps->a->index) & ft_power(2, i))
// 					ra(ps);
// 				else
// 					pb(ps);
// 				list[0]--;
// 				if (is_sorted(ps->a))
// 					break;
// 			}
// 			else if (list[1])
// 			{
// 				if ((ps->b->index) & ft_power(2, i))
// 					pa(ps);
// 				else
// 					rb(ps);
// 				list[1]--;
// 				if (is_descending(ps->b))
// 					break;
// 			}
// 			if (is_sorted(ps->a) && is_descending(ps->b))
// 				break ;
// 		}
// 		i++;
// 		if (i == bits || ft_stack_size(ps->a) >= ft_stack_size(ps->b))
// 			while (ps->b)
// 				pa(ps);
// 		else
// 			while (ps->a)
// 				pb(ps);
// 	}
// }


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

int	ft_power(int base, int exp)
{
	int	result;

	if ((base == 0 && exp == 0) || exp < 0 || (base == 0 && exp < 0))
		exit(1);	
	if (base == 1 || exp == 0)
		return (1);
	if (base == 0 && exp != 0)
		return (0);
	result = 1;
	while (exp)
	{
		result *= base;
		exp--;
	}
	return (result);
}

void	pre_optimizers(t_puswap *ps, int remaining)
{
	// if (ps->a && ps->a->next)
	// {
	// 	if (ps->a > ps->a->next)
	// 		sa(ps);
	// }
	// if (ps->b && ps->b->next)
	// {
	// 	if (ps->b < ps->b->next)
	// 		sb(ps);
	// }
	(void)remaining;
	if (ft_stack_size(ps->a) == 5)
		sort_five(ps);
	// if (remaining == (ps->list_size - 5))
	// 	sort_five_b(ps);
}

// void	post_optimizers(t_puswap *ps, int remaining)
// {
// 	if ()
// }