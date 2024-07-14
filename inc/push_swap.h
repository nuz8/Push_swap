/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:36:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/14 06:30:25 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/includes/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define _pa pa(&a, &b)
# define _pb pb(&a, &b)

# define _sa sa(&a)
# define _sb sb(&b)
# define _ss ss(&a, &b)

# define _ra ra(&a)
# define _rb rb(&b)
# define _rr rr(&a, &b)

# define _rra rra(&a)
# define _rrb rrb(&b)
# define _rrr rrr(&a, &b)

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

// list_fns.c: functions adapted from libft
t_stack	*ft_stack_new(long lnum);
t_stack	*ft_stack_last(t_stack *stk);
void	ft_stack_addback(t_stack **root, t_stack *new);
void	ft_stack_free(t_stack **root);
int		ft_stack_size(t_stack *root);
void	ft_stack_minmax(t_stack *root, int *minmax);

// void	ft_stackadd_front(t_stack **stk, t_stack *new);
// void	ft_stackclear(t_stack **stk, void (*del)(void *));
// void	ft_stackdelone(t_stack *stk, void (*del)(void*));
// void	ft_stackiter(t_stack *stk, void (*f)(void *));
// t_stack	*ft_stack_last(t_stack *stk);
// t_stack	*ft_stackmap(t_stack *stk, void *(*f)(void *), void (*del)(void *));

// op_push.c
void	push_stack(t_stack **receiver, t_stack **sender);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// op_swap.c
void	swap_stack(t_stack **root);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// op_rotate.c
void	rotate_stack(t_stack **root);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// op_rev_rotate.c
void	rev_rotate_stack(t_stack **root);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// algorithm.c
void	start_sorting(t_stack **a, t_stack **b);
// void	start_sorting(t_stack **a);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b, int list_size);

// utils.c
void	frexit(char *str, t_stack **root, char **split, int ec);

void	print_stack_contents(t_stack *root);
void	print_stacks(t_stack *a, t_stack *b);

#endif
