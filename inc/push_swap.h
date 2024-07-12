/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:36:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/12 06:06:52 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/includes/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_stack
{
	int				index;
	long			lnum;
	int				num;
	struct s_stack	*next;
}				t_stack;



// parsing.c
void	parse_and_handle_errors(t_stack **root, int argc, char **argv);
void	parse_numstr(t_stack **root, char *num_str);
void	parse_nums(t_stack **root, char **argv);
long	ft_atol(const char *str);

// error_checks.c
void	check_digits_numstr(char *num_str);
void	check_digits_argv(char **argv);
void	avoid_long(t_stack **root);
void	avoid_duplicates(t_stack **root);
void	check_sorted(t_stack **root);

// utils.c
void	frexit(char *str, t_stack **root, char **split, int ec);

// list_fns.c: functions adapted from libft
t_stack	*ft_stack_new(long lnum);
void	ft_stackadd_front(t_stack **stk, t_stack *new);
void	ft_stack_addback(t_stack **stk, t_stack *new);
void	ft_stackclear(t_stack **stk, void (*del)(void *));
void	ft_stackdelone(t_stack *stk, void (*del)(void*));
void	ft_stackiter(t_stack *stk, void (*f)(void *));
t_stack	*ft_stack_last(t_stack *stk);
t_stack	*ft_stackmap(t_stack *stk, void *(*f)(void *), void (*del)(void *));
int		ft_stacksize(t_list *stk);

#endif
