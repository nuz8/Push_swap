/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:35:36 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/17 02:03:28 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_puswap	*ps;
	// t_stack		*a;
	// t_stack		*b;

	if (argc < 2)
		return (1);
	ps = malloc(sizeof(t_puswap));
	ps->a = NULL;
	ps->b = NULL;
	if (argc >= 2)
	{
		parse_and_handle_errors(ps, argc, argv);
		
		// print_stack_contents(ps->a);
		// print_stacks(ps);

		start_sorting(ps);
		
		// print_stacks(ps);
		// print_stack_contents(ps->a);
		
	// 	if (is_sorted(ps->a))
	// 		ft_putstr_fd("OK\t", 2);
	// 	else
	// 		ft_putstr_fd("KO\t", 2);
	}
	ft_stack_free(&(ps->a));
	ft_stack_free(&(ps->b));
	free(ps);

	// ft_putnbr_fd(ps->total_moves, 2);
	return (0);
}
