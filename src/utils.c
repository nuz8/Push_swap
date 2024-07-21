/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:49:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/22 00:54:11 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_power(int base, int exp);
void	frexit(char *str, t_puswap *ps, char **split, int ec);

int	ft_power(int base, int exp)
{
	int	result;

	if ((base == 0 && exp == 0) || exp < 0 || (base == 0 && exp < 0))
		exit(1);	
	if (base == 1 || exp == 0)
		return (1);
	if (base == 0 && exp != 0)
		return (0);
	result = 1;
	while (exp)
	{
		result *= base;
		exp--;
	}
	return (result);
}

void	frexit(char *str, t_puswap *ps, char **split, int ec)
{
	int	fd;
	
	if (ec == 0)
		fd = 1;
	else
		fd = 2;
	if (str)
		ft_putstr_fd(str, fd);
	if (ps->a)
		ft_stack_free(&(ps->a));
	if (ps->b)
		ft_stack_free(&(ps->b));
	if (split)
		ft_free2d(split);
	if (ps)
		free(ps);
	exit(ec);
}
