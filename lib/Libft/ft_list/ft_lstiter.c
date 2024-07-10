/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:19:42 by pamatya           #+#    #+#             */
/*   Updated: 2024/03/25 01:19:42 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f((*lst).content);
		lst = lst->next;
	}
}

void	ft_stackiter(t_stack *stk, void (*f)(void *))
{
	if (!stk || !f)
		return ;
	while (stk)
	{
		f(stk->num);
		f(stk->index);
		stk = stk->next;
	}
}
