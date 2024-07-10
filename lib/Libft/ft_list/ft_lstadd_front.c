/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:31:07 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/11 01:00:15 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		return ;
}

void	ft_stackadd_front(t_stack **stk, t_stack *new)
{
	if (stk && new)
	{
		new->next = *stk;
		*stk = new;
	}
	else
		return ;
}
