/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 02:41:02 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/22 00:53:58 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_digits_numstr(t_puswap *ps, char *num_str);
void	check_digits_argv(t_puswap *ps, char **argv);
void	avoid_long(t_puswap *ps);
void	avoid_duplicates(t_puswap *ps);
void	avoid_lesinvalides(t_puswap *ps, int argc, char **argv);

void	check_digits_numstr(t_puswap *ps, char *num_str)
{
	int	i;

	i = 0;
	if (num_str[i] == '\0')
			frexit("Error\n", ps, NULL, 2);
	while (num_str[i])
	{
		if (!ft_isdigit(num_str[i]) && num_str[i] != ' ' && num_str[i] != '-')
			frexit("Error\n", ps, NULL, 2);
		i++;
	}
}

void	check_digits_argv(t_puswap *ps, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' 
			&& argv[i][j] != '-')
				frexit("Error\n", ps, NULL, 2);
			j++;
		}
		i++;
	}
}

void	avoid_long(t_puswap *ps)
{
	t_stack	*cur;

	cur = ps->a;
	while (cur)
	{
		if (cur->lnum > INT_MAX || cur->lnum < INT_MIN)
			frexit("Error\n", ps, NULL, 2);
		else
		{
			cur->num = (int)cur->lnum;
			cur->lnum = 0;
		}
		cur = cur->next;
	}
}

void	avoid_duplicates(t_puswap *ps)
{
	t_stack	*cur[2];
	
	cur[0] = ps->a;
	while (cur[0])
	{
		cur[1] = cur[0]->next;
		while (cur[1])
		{
			if (cur[0]->num == cur[1]->num)
				frexit("Error\n", ps, NULL, 2);
			cur[1] = cur[1]->next;
		}
		cur[0] = cur[0]->next;
	}
}

void	avoid_lesinvalides(t_puswap *ps, int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (((argv[i][j] == '-' || argv[i][j] == '+') && 
			argv[i][j + 1] == ' ') || (ft_isdigit(argv[i][j]) && 
			(argv[i][j + 1] == '-' || argv[i][j + 1] == '+')) || 
			(argv[i][j] == '-' && (argv[i][j + 1] == '-' || 
			argv[i][j + 1] == '\0')))
				frexit("Error\n", ps, NULL, 2);
			j++;
		}
		if (argc == 2)
			break ;
		i++;
	}	
}
