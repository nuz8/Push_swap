/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:30:29 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/15 04:42:00 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	parse_and_handle_errors(t_stack **root, int argc, char **argv);
void	parse_numstr(t_stack **root, char *num_str);
void	parse_nums(t_stack **root, char **argv);
long	ft_atol(const char *str);

// Function to check for errors
void	parse_and_handle_errors(t_stack **root, int argc, char **argv)
{
	if (argc == 2)
	{
		check_digits_numstr(argv[1]);
		parse_numstr(root, argv[1]);
	}
	else
	{
		check_digits_argv(argv);
		parse_nums(root, argv);
	}
	avoid_long(root);
	avoid_duplicates(root);
	if (is_sorted(root))
		frexit("Error in check_sorted\n", root, NULL, 2);
		// frexit("Error\n", root, NULL, 2);
}

// Function to parse the input string when argc =2, and create a linked list of integers
void	parse_numstr(t_stack **root, char *num_str)
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
				frexit("Error: node malloc\n", root, split, 3);
			ft_stack_addback(root, cur);
		}
		else
			frexit("Error: from parse_numstr\n", root, split, 2);
			// frexit("Error\n", root, split, 2);
		i++;
	}
	ft_free2d(split);
}

// Function to parse the integer character inputs (i.e. argc > 2), and create a linked list of integers
void	parse_nums(t_stack **root, char **argv)
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
				frexit("EError: node malloc\n", root, NULL, 3);
			ft_stack_addback(root, cur);
		}
		else
			frexit("Error: from parse_nums\n", root, NULL, 2);
			// frexit("Error\n", root, NULL, 2);
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

// // Function to convert a string to a long integer (works with whitespaces)
// long	ft_atol(const char *str)
// {
// 	int		signe;
// 	long	num;
// 	int		i;

// 	signe = 1;
// 	num = 0;
// 	i = 0;
// 	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
// 		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
// 		i ++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			signe = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 		num = num * 10 + (str[i++] - '0');
// 	num = signe * num;
// 	return (num);
// }