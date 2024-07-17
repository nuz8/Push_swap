/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:30:29 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/17 02:47:15 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	parse_and_handle_errors(t_stack **root, int argc, char **argv);
// void	parse_numstr(t_stack **root, char *num_str);
// void	parse_nums(t_stack **root, char **argv);
// long	ft_atol(const char *str);

void	parse_and_handle_errors(t_puswap *ps, int argc, char **argv);
void	parse_numstr(t_puswap *ps, char *num_str);
void	parse_nums(t_puswap *ps, char **argv);
long	ft_atol(const char *str);

// Function to check for errors
// void	parse_and_handle_errors(t_stack **root, int argc, char **argv)
void	parse_and_handle_errors(t_puswap *ps, int argc, char **argv)
{
	if (argc == 2)
	{
		check_digits_numstr(argv[1]);
		parse_numstr(ps, argv[1]);
	}
	else
	{
		check_digits_argv(argv);
		parse_nums(ps, argv);
	}
	avoid_long(ps);
	avoid_duplicates(ps);
	if (is_sorted(ps->a))
		frexit(NULL, ps, NULL, 1);
		// frexit("Error in check_sorted\n", ps, NULL, 2);
}

// Function to parse the input string when argc =2, and create a linked list of integers
// void	parse_numstr(t_stack **root, char *num_str)
void	parse_numstr(t_puswap *ps, char *num_str)
{
	char	**split;
	t_stack	*cur;
	int		i;

	split = ft_split(num_str, ' ');
	if(!split)
		frexit("Error: split\n", NULL, NULL, 3);
		// frexit("Error\n", NULL, NULL, 3);
	i = 0;
	while (split[i])
	{
		if (ft_isdigit(*split[i]) || *split[i] == '-')
		{
			cur = ft_stack_new(ft_atol(split[i]));
			if (!cur)
				frexit("Error: node malloc\n", ps, split, 3);
			ft_stack_addback(&(ps->a), cur);
		}
		else
			frexit("Error: from parse_numstr\n", ps, split, 2);
			// frexit("Error\n", ps, split, 2);
		i++;
	}
	ft_free2d(split);
}

// Function to parse the integer character inputs (i.e. argc > 2), and create a linked list of integers
// void	parse_nums(t_stack **root, char **argv)
void	parse_nums(t_puswap *ps, char **argv)
{
	t_stack	*cur;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigit(*argv[i]) || *argv[i] == '-')
		{
			cur = ft_stack_new(ft_atol(argv[i]));
			if (!cur)
				frexit("EError: node malloc\n", ps, NULL, 3);
			ft_stack_addback(&(ps->a), cur);
		}
		else
			frexit("Error: from parse_nums\n", ps, NULL, 2);
			// frexit("Error\n", ps, NULL, 2);
		i++;
	}
}

// Function to convert a string to a long integer
long	ft_atol(const char *str)
{
	long	signe;
	long	num;
	int		i;

	signe = 1;
	num = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	num = signe * num;
	return (num);
}
