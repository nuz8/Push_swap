/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:52:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/20 23:57:06 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stack_new(long lnum);
t_stack	*ft_stack_last(t_stack *stk);
void	ft_stack_addback(t_stack **root, t_stack *new);
int		ft_stack_size(t_stack *root);
void	ft_stack_free(t_stack **root);

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

void	ft_stack_free(t_stack **root)
{
	t_stack	*del_node;
	t_stack	*free_node;

	if (!root || !*root)
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
