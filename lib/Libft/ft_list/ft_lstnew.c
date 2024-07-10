/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:51:39 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/11 01:37:57 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

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
