/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:36:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/12 02:40:02 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/includes/libft.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}				t_stack;




// list_fns.c: functions adapted from libft
t_stack	*ft_stack_new(void *content);
void	ft_stackadd_front(t_stack **stk, t_stack *new);
void	ft_stackadd_back(t_stack **stk, t_stack *new);
void	ft_stackclear(t_stack **stk, void (*del)(void *));
void	ft_stackdelone(t_stack *stk, void (*del)(void*));
void	ft_stackiter(t_stack *stk, void (*f)(void *));
t_stack	*ft_stacklast(t_stack *stk);
t_stack	*ft_stackmap(t_stack *stk, void *(*f)(void *), void (*del)(void *));
int		ft_stacksize(t_list *stk);

#endif