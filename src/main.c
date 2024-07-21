/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:35:36 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/21 04:25:32 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_puswap	*ps;

	if (argc < 2)
		return (1);
	ps = malloc(sizeof(t_puswap));
	if (!ps)
		frexit(2, "Malloc error\n", NULL, NULL, 3);
	ps->a = NULL;
	ps->b = NULL;
	if (argc >= 2)
	{
		parse_and_handle_errors(ps, argc, argv);
		start_sorting(ps);
	}
	
	ft_stack_free(&(ps->a));
	ft_stack_free(&(ps->b));
	free(ps);
	return (0);
}
