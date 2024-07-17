/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:52:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/17 00:17:15 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stack_new(long lnum);
t_stack	*ft_stack_last(t_stack *stk);
void	ft_stack_addback(t_stack **root, t_stack *new);
void	ft_stack_free(t_stack **root);
int		ft_stack_size(t_stack *root);
// void	ft_stack_minmax(t_stack *root, int *minmax);
void	ft_stack_minmax(t_puswap *ps);
int		ft_stack_min(t_stack *root);
int		ft_stack_max(t_stack *root);

// Used functions from list-manipulations for stack

t_stack	*ft_stack_new(long lnum)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->lnum = lnum;
	new_node->num = 0;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_stack_last(t_stack *stk)
{
	if (!stk)
		return (NULL);
	while (stk->next)
		stk = stk->next;
	return (stk);
}

void	ft_stack_addback(t_stack **root, t_stack *new)
{
	t_stack	*last;

	if (!root || !new)
		return ;
	if (!*root)
	{
		*root = new;
		return ;
	}
	last = ft_stack_last(*root);
	last->next = new;
}

void	ft_stack_free(t_stack **root)
{
	t_stack	*del_node;
	t_stack	*free_node;

	if (!root)
		return ;
	del_node = *root;
	while (del_node)
	{
		free_node = del_node;
		del_node = del_node->next;
		free(free_node);
	}
	*root = NULL;
}

int	ft_stack_size(t_stack *root)
{
	int	i;

	if (!root)
		return (0);
	i = 1;
	while (root->next != NULL)
	{
		i++;
		root = root->next;
	}
	return (i);
}

// void	ft_stack_minmax(t_stack *root, int *minmax)
void	ft_stack_minmax(t_puswap *ps)
{
	t_stack	*cur;
	
	ps->minmax[0] = ps->a->num;
	ps->minmax[1] = ps->a->num;
	cur = ps->a;
	while (cur)
	{
		if (cur->num < ps->minmax[0])
			ps->minmax[0] = cur->num;
		if (cur->num > ps->minmax[1])
			ps->minmax[1] = cur->num;
		cur = cur->next;
	}
}

int	ft_stack_min(t_stack *root)
{
	int	min;
	t_stack	*cur;

	min = root->num;
	cur = root;
	while (cur)
	{
		if (cur->num < min)
			min = cur->num;
		cur = cur->next;
	}
	return (min);
}

int	ft_stack_max(t_stack *root)
{
	int	max;
	t_stack	*cur;

	max = root->num;
	cur = root;
	while (cur)
	{
		if (cur->num > max)
			max = cur->num;
		cur = cur->next;
	}
	return (max);
}

// ft_stack_dup()
// {
	
// }

/* ************************************************************************** */

// Unused functions from list-manipulations

// void	ft_stackadd_front(t_stack **stk, t_stack *new)
// {
// 	if (stk && new)
// 	{
// 		new->next = *stk;
// 		*stk = new;
// 	}
// 	else
// 		return ;
// }

// void	ft_stackclear(t_stack **lst, void (*del)(void *))
// {
// 	t_stack	*del_node;
// 	t_stack	*free_node;

// 	if (!lst || !del)
// 		return ;
// 	del_node = *lst;
// 	while (del_node)
// 	{
// 		free_node = del_node;
// 		del(del_node);
// 		del_node = del_node->next;
// 		free(free_node);
// 	}
// 	*lst = NULL;
// }

// void	ft_stackdelone(t_stack *stk, void (*del)(void*))
// {
// 	if (!stk && !del)
// 		return ;
// 	del(stk->num);
// 	del(stk->index);
// 	free(stk);
// }

// void	ft_stackiter(t_stack *stk, void (*f)(void *))
// {
// 	if (!stk || !f)
// 		return ;
// 	while (stk)
// 	{
// 		f(stk->num);
// 		f(stk->index);
// 		stk = stk->next;
// 	}
// }

// t_stack	*ft_stackmap(t_stack *stk, void *(*f)(void *), void (*del)(void *))
// {
// 	t_stack	*new_stk;
// 	t_stack	*node;
// 	t_stack	*content;

// 	if (!stk || !f || !del)
// 		return (NULL);
// 	new_stk = NULL;
// 	while (stk)
// 	{
// 		content->num = f(stk->num);
// 		content->index = f(stk->index);
// 		node = ft_stacknew(content);
// 		ft_stackadd_back(&new_stk, node);
// 		if (!node || !new_stk)
// 			return (del(content), ft_stackclear(&new_stk, del), NULL);
// 		stk = stk->next;
// 	}
// 	return (new_stk);
// }

