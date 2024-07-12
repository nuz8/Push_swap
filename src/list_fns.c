/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:52:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/12 02:40:32 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stack_new(void *content)
{
	t_stack	*new_node;
	t_stack	*cont;

	new_node = malloc(sizeof(t_stack));
	cont = content;
	if (!new_node)
		return (NULL);
	new_node->num = cont->num;
	new_node->index = cont->index;
	new_node->next = NULL;
	return (new_node);
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

void	ft_stackclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*del_node;
	t_stack	*free_node;

	if (!lst || !del)
		return ;
	del_node = *lst;
	while (del_node)
	{
		free_node = del_node;
		del(del_node);
		del_node = del_node->next;
		free(free_node);
	}
	*lst = NULL;
}

void	ft_stackdelone(t_stack *stk, void (*del)(void*))
{
	if (!stk && !del)
		return ;
	del(stk->num);
	del(stk->index);
	free(stk);
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

t_stack	*ft_stacklast(t_stack *stk)
{
	if (!stk)
		return (NULL);
	while (stk->next)
		stk = stk->next;
	return (stk);
}

t_stack	*ft_stackmap(t_stack *stk, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*new_stk;
	t_stack	*node;
	t_stack	*content;

	if (!stk || !f || !del)
		return (NULL);
	new_stk = NULL;
	while (stk)
	{
		content->num = f(stk->num);
		content->index = f(stk->index);
		node = ft_stacknew(content);
		ft_stackadd_back(&new_stk, node);
		if (!node || !new_stk)
			return (del(content), ft_stackclear(&new_stk, del), NULL);
		stk = stk->next;
	}
	return (new_stk);
}

int	ft_stacksize(t_list *stk)
{
	int	i;

	if (!stk)
		return (0);
	i = 1;
	while (stk->next != NULL)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}
