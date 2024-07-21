/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:30:29 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/22 00:53:55 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	parse_and_handle_errors(t_puswap *ps, int argc, char **argv);
void	parse_numstr(t_puswap *ps, char *num_str);
void	parse_nums(t_puswap *ps, char **argv);
long	ft_atol(const char *str);

void	parse_and_handle_errors(t_puswap *ps, int argc, char **argv)
{
	if (argc == 2)
	{
		check_digits_numstr(ps, argv[1]);
		avoid_lesinvalides(ps, argc, argv);
		parse_numstr(ps, argv[1]);
	}
	else
	{
		check_digits_argv(ps, argv);
		avoid_lesinvalides(ps, argc, argv);
		parse_nums(ps, argv);
	}
	avoid_long(ps);
	avoid_duplicates(ps);
	if (is_sorted(ps->a))
		frexit(NULL, ps, NULL, 1);
}

// New function to parse the input string when argc =2, and create a linked list of integers
void	parse_numstr(t_puswap *ps, char *num_str)
{
	char	**split;
	t_stack	*cur;
	int		i;

	split = ft_split(num_str, ' ');
	if(!split)
		frexit("Error: split\n", NULL, NULL, 3);
	i = 0;
	while (split[i])
	{
		cur = ft_stack_new(ft_atol(split[i]));
		if (!cur)
			frexit("Error: node malloc\n", ps, split, 3);
		ft_stack_addback(&(ps->a), cur);
		i++;
	}
	ft_free2d(split);
}

// New function to parse the integer character inputs (i.e. argc > 2), and create a linked list of integers
void	parse_nums(t_puswap *ps, char **argv)
{
	t_stack	*cur;
	char	**split;
	int		i;
	int		si;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			frexit("Error: split\n", ps, NULL, 3);
		si = 0;
		while (split[si])
		{
			cur = ft_stack_new(ft_atol(split[si]));
			if (!cur)
				frexit("Error: node malloc\n", ps, split, 3);
			ft_stack_addback(&(ps->a), cur);	
			si++;
		}
		ft_free2d(split);
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
