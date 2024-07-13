/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:35:36 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/13 04:58:50 by pamatya          ###   ########.fr       */
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
		_pb;
		print_stacks(a, b);
		_pb;
		print_stacks(a, b);
		_ra;
		print_stacks(a, b);
		_rb;
		print_stacks(a, b);
		_rr;
		print_stacks(a, b);
		_sa;
		print_stacks(a, b);
		_sb;
		print_stacks(a, b);
		_ss;
		print_stacks(a, b);
		_rra;
		print_stacks(a, b);
		_rrb;
		print_stacks(a, b);
		_rrr;
		print_stacks(a, b);
		_pa;
		print_stacks(a, b);
	}


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