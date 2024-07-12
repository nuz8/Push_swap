/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:30:29 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/12 02:34:13 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	parse_numstr(char *str, t_stack *a)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		if (ft_isdigit(split[i][j]) || split[i][j] == '-')
		{
			a->n = ft_atoi(split[i]);
			a->index = i;
			a->next = (t_stack *)malloc(sizeof(t_stack));
			a = a->next;
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

// void	parse_numstr(char *str, t_stack **a)
// {
// 	char	**split;
// 	int		i;
// 	t_stack	*new;

// 	i = 0;
// 	split = ft_split(str, ' ');
// 	while (split[i])
// 	{
// 		new = (t_stack *)malloc(sizeof(t_stack));
// 		new->n = ft_atoi(split[i]);
// 		new->index = i;
// 		new->next = *a;
// 		*a = new;
// 		i++;
// 	}
// }