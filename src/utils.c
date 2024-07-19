/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/18 23:56:40 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	frexit(char *str, t_stack **root, char **split, int ec);
// void	print_stack_contents(t_stack *root);
// void	print_stacks(t_stack *a, t_stack *b);

void	frexit(char *str, t_puswap *ps, char **split, int ec);
void	print_stack_contents(t_stack *root);
void	print_stacks(t_puswap *ps);

void	frexit(char *str, t_puswap *ps, char **split, int ec)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (ps->a)
		ft_stack_free(&(ps->a));
	if (split)
		ft_free2d(split);
	if (ps)
		free(ps);
	exit(ec);
}

// Function to print the stack
void	print_stack_contents(t_stack *root)
{
	t_stack	*cur;

	cur = root;
	ft_putstr_fd("========================================\n", 2);
	ft_putstr_fd("index\t\t", 2);
	ft_putstr_fd("lnum\t\t", 2);
	ft_putstr_fd("num\n", 2);
	ft_putstr_fd("----------------------------------------\n", 2);
	while (cur)
	{
		ft_putnbr_fd(cur->index, 2);
		ft_putstr_fd("\t\t", 2);
		ft_putlong_fd(cur->lnum, 2);
		ft_putstr_fd("\t\t", 2);
		ft_putnbr_fd(cur->num, 2);
		ft_putstr_fd("\n", 2);
		cur = cur->next;
	}
	ft_putstr_fd("========================================\n", 2);
	ft_putstr_fd("\n", 2);
}

// Function to print two stacks side by side
void	print_stacks(t_puswap *ps)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = ps->a;
	cur_b = ps->b;
	ft_putstr_fd("========================================\n", 2);
	while (cur_a || cur_b)
	{
		if (cur_a)
		{
			ft_putnbr_fd(cur_a->num, 2);
			cur_a = cur_a->next;
			ft_putstr_fd("\t\t", 2);
		}
		// else
		// 	ft_putstr_fd("\t\t", 2);
		ft_putstr_fd("|", 2);
		if (cur_b)
		{
			ft_putstr_fd("\t\t", 2);
			ft_putnbr_fd(cur_b->num, 2);
			cur_b = cur_b->next;
		}
		ft_putstr_fd("\n", 2);
	}
	ft_putstr_fd("----------------------------------------\n", 2);
	ft_putstr_fd("stack a\t\t|\t\t", 2);
	ft_putstr_fd("stack b\n", 2);
	ft_putstr_fd("========================================\n", 2);
	ft_putstr_fd("\n", 2);
}
