/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:42:07 by pamatya           #+#    #+#             */
/*   Updated: 2024/03/25 00:42:07 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	ft_stackadd_back(t_stack **stk, t_stack *new)
{
	t_stack	*last;

	if (!stk || !new)
		return ;
	if (!*stk)
	{
		*stk = new;
		return ;
	}
	last = ft_stacklast(*stk);
	last->next = new;
}
