/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/12 06:06:42 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	frexit(char *str, t_stack **root, char **split, int ec);

void	frexit(char *str, t_stack **root, char **split, int ec)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (root)
		ft_stackfree(root);
	if (split)
		ft_free2d(split);
	exit(ec);
}

// Function to print the stack
void	print_stack(t_stack *root)
{
	t_stack	*cur;

	cur = root;
	while (cur)
	{
		ft_putnbr_fd(cur->index, 1);
		ft_putstr_fd("\t", 1);
		ft_putnbr_fd(cur->lnum, 1);
		ft_putstr_fd("\t", 1);
		ft_putnbr_fd(cur->num, 1);
		ft_putstr_fd("\n", 1);
		cur = cur->next;
	}
}
