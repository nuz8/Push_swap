/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:35:36 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/15 23:27:31 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
		// print_stack_contents(a);
		// print_stacks(a, b);
		start_sorting(&a, &b);
		// print_stacks(a, b);
		// print_stack_contents(a);
		if (is_sorted(&a))
			ft_putstr_fd("OK\t", 2);
		else
			ft_putstr_fd("KO\t", 2);
	}
	ft_stack_free(&a);
	ft_stack_free(&b);
	return (0);
}
