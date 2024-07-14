/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/14 06:29:49 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	frexit(char *str, t_stack **root, char **split, int ec);
void	print_stack_contents(t_stack *root);
void	print_stacks(t_stack *a, t_stack *b);

void	frexit(char *str, t_stack **root, char **split, int ec)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (root)
		ft_stack_free(root);
	if (split)
		ft_free2d(split);
	exit(ec);
}

// Function to print the stack
void	print_stack_contents(t_stack *root)
{
	t_stack	*cur;

	cur = root;
	ft_putstr_fd("index\t\t", 1);
	ft_putstr_fd("lnum\t\t", 1);
	ft_putstr_fd("num\n", 1);
	while (cur)
	{
		ft_putnbr_fd(cur->index, 1);
		ft_putstr_fd("\t\t", 1);
		ft_putlong_fd(cur->lnum, 1);
		ft_putstr_fd("\t\t", 1);
		ft_putnbr_fd(cur->num, 1);
		ft_putstr_fd("\n", 1);
		cur = cur->next;
	}
	ft_putstr_fd("\n", 1);
}

// Function to print two stacks side by side
void	print_stacks(t_stack *a, t_stack *b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = a;
	cur_b = b;
	ft_putstr_fd("----------------------------------------\n", 1);
	while (cur_a || cur_b)
	{
		if (cur_a)
		{
			ft_putnbr_fd(cur_a->num, 1);
			cur_a = cur_a->next;
			ft_putstr_fd("\t\t", 1);
		}
		// else
		// 	ft_putstr_fd("\t\t", 1);
		ft_putstr_fd("|", 1);
		if (cur_b)
		{
			ft_putstr_fd("\t\t", 1);
			ft_putnbr_fd(cur_b->num, 1);
			cur_b = cur_b->next;
		}
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("----------------------------------------\n", 1);
	ft_putstr_fd("stack a\t\t|\t\t", 1);
	ft_putstr_fd("stack b\n", 1);
	ft_putstr_fd("----------------------------------------\n", 1);
	ft_putstr_fd("\n", 1);
}
