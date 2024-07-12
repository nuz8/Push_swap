/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 02:41:02 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/12 05:40:14 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_digits_numstr(char *num_str);
void	check_digits_argv(char **argv);
void	avoid_long(t_stack **root);
void	avoid_duplicates(t_stack **root);
void	check_sorted(t_stack **root);

// Function to check if the input string contains only integers (if argc = 2)
// If not, exit the program with exit code 2
void	check_digits_numstr(char *num_str)
{
	int	i;

	i = 0;
	while (num_str[i])
	{
		if (!ft_isdigit(num_str[i]) && num_str[i] != ' ' && num_str[i] != '-')
			frexit("Error\n", NULL, NULL, 2);
		i++;
	}
}

// Function to check if the input string contains only integers (if argc > 2)
// If not, exit the program with exit code 2
void	check_digits_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				frexit("Error\n", NULL, NULL, 2);
			j++;
		}
		i++;
	}
}

// Function to check if all values are integers: if yes, copy them as integers, else exit
void	avoid_long(t_stack **root)
{
	t_stack	*cur;

	cur = *root;
	while (cur)
	{
		if (cur->lnum > INT_MAX || cur->lnum < INT_MIN)
			frexit("Error\n", root, NULL, 2);
		else
		{
			cur->num = (int)cur->lnum;
			cur->lnum = 0;
		}
		cur = cur->next;
	}
}

// Function to check if there are any duplicates
void	avoid_duplicates(t_stack **root)
{
	t_stack	*cur[2];
	
	cur[0] = *root;
	while (cur[0])
	{
		cur[1] = cur[0]->next;
		while (cur[1])
		{
			if (cur[0]->num == cur[1]->num)
				frexit("Error\n", root, NULL, 2);
			cur[1] = cur[1]->next;
		}
		cur[0] = cur[0]->next;
	}
}

// Function to check if the linked list is already sorted
void	check_sorted(t_stack **root)
{
	t_stack	*cur;

	cur = *root;
	while (cur->next)
	{
		if (cur->num > cur->next->num)
			frexit("Error\n", root, NULL, 2);
		cur = cur->next;
	}
}
