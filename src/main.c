/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:35:36 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/15 07:40:56 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// int	main_algorithm(int argc, char **argv, char **envp)
// {
// 	t_stack	a;
// 	t_stack	b;
	
// 	if (argc < 2)
// 		return (1);;
// 	if (argc == 2)
// 	{
// 		// parse the string
// 		// split the string first and then store it in a linked list (use atol)
// 		// check if all the values are integers, if not return
// 		// check if there are any duplicates, if yes then return
// 		// check if the linked list is already sorted, if yes then return	
// 	}
// 	if (argc > 2)
// 	{
// 		// read the char arguments, and store the converted int values into a linked list (use atol)
// 		// check if all the values are integers, if not return
// 		// check if there are any duplicates, if yes then return
// 		// check if the linked list is already sorted, if yes then return
// 	}
// 	// begin the sorting algorithm

// 	return (0);
// }

// void	demo(t_stack **a, t_stack **b)
// {
// 	print_stacks(a, b);
// 		pb(a, b);
// 		print_stacks(a, b);
// 		pb(a, b);
// 		print_stacks(a, b);
// 		pb(a, b);
// 		print_stacks(a, b);
// 		ra(a);
// 		print_stacks(a, b);
// 		rb(b);
// 		print_stacks(a, b);
// 		rr(a, b);
// 		print_stacks(a, b);
// 		sa(a);
// 		print_stacks(a, b);
// 		sb(b);
// 		print_stacks(a, b);
// 		ss(a, b);
// 		print_stacks(a, b);
// 		rra(a);
// 		print_stacks(a, b);
// 		rrb(b);
// 		print_stacks(a, b);
// 		rrr(a, b);
// 		print_stacks(a, b);
// 		pa(a, b);
// 		print_stacks(a, b);
// 		pa(a, b);
// 		print_stacks(a, b);
// 		pa(a, b);
// 		print_stacks(a, b);
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (argc >= 2)
	{
		parse_and_handle_errors(&a, argc, argv);
		// parse_and_handle_errors(&b, argc, argv);
		// demo(&a, &b);
		print_stack_contents(a);
		print_stacks(a, b);
		start_sorting(&a, &b);
		print_stacks(a, b);
		print_stack_contents(a);
	}
	ft_stack_free(&a);
	ft_stack_free(&b);
	return (0);
}

	// if (argc > 2)
	// {
	// 	// read the char arguments, and store the converted int values into a linked list (use atol)
	// 	// check if all the values are integers, if not return
	// 	// check if there are any duplicates, if yes then return
	// 	// check if the linked list is already sorted, if yes then return
	// }
	// // begin the sorting algorithm