/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:52:11 by pamatya           #+#    #+#             */
/*   Updated: 2024/03/25 00:52:11 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst && !del)
		return ;
	del((*lst).content);
	free(lst);
}

void	ft_stackdelone(t_stack *stk, void (*del)(void*))
{
	if (!stk && !del)
		return ;
	del(stk->num);
	del(stk->index);
	free(stk);
}
