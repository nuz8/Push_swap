/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:36:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/17 04:11:58 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/includes/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// # define _pa pa(&a, &b)
// # define _pb pb(&a, &b)

// # define _sa sa(&a)
// # define _sb sb(&b)
// # define _ss ss(&a, &b)

// # define _ra ra(&a)
// # define _rb rb(&b)
// # define _rr rr(&a, &b)

// # define _rra rra(&a)
// # define _rrb rrb(&b)
// # define _rrr rrr(&a, &b)

typedef struct s_stack
{
	int				index;
	long			lnum;
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_puswap
{
	t_stack	*a;
	t_stack	*b;
	int		list_size;
	int		minmax[2];
	int		total_moves;
}	t_puswap;

// parsing.c
// void	parse_and_handle_errors(t_stack **root, int argc, char **argv);
// void	parse_numstr(t_stack **root, char *num_str);
// void	parse_nums(t_stack **root, char **argv);
// long	ft_atol(const char *str);
void	parse_and_handle_errors(t_puswap *ps, int argc, char **argv);
void	parse_numstr(t_puswap *ps, char *num_str);
void	parse_nums(t_puswap *ps, char **argv);
long	ft_atol(const char *str);

// error_checks.c
void	check_digits_numstr(char *num_str);
void	check_digits_argv(char **argv);
// void	avoid_long(t_stack **root);
// void	avoid_duplicates(t_stack **root);
// int		is_sorted(t_stack **root);
void	avoid_long(t_puswap *ps);
void	avoid_duplicates(t_puswap *ps);
int		is_sorted(t_stack *root);

// list_fns.c: functions adapted from libft
t_stack	*ft_stack_new(long lnum);
t_stack	*ft_stack_last(t_stack *stk);
void	ft_stack_addback(t_stack **root, t_stack *new);
void	ft_stack_free(t_stack **root);
int		ft_stack_size(t_stack *root);
// void	ft_stack_minmax(t_stack *root, int *minmax[2]);
void	ft_stack_minmax(t_puswap *ps);
int		ft_stack_min(t_stack *root);
int		ft_stack_max(t_stack *root);

// void	ft_stackadd_front(t_stack **stk, t_stack *new);
// void	ft_stackclear(t_stack **stk, void (*del)(void *));
// void	ft_stackdelone(t_stack *stk, void (*del)(void*));
// void	ft_stackiter(t_stack *stk, void (*f)(void *));
// t_stack	*ft_stack_last(t_stack *stk);
// t_stack	*ft_stackmap(t_stack *stk, void *(*f)(void *), void (*del)(void *));

// op_push.c
void	push_stack(t_stack **receiver, t_stack **sender);
void	pa(t_puswap *ps);
void	pb(t_puswap *ps);

// op_swap.c
void	swap_stack(t_stack **root);
void	sa(t_puswap *ps);
void	sb(t_puswap *ps);
void	ss(t_puswap *ps);

// op_rotate.c
void	rotate_stack(t_stack **root);
void	ra(t_puswap *ps);
void	rb(t_puswap *ps);
void	rr(t_puswap *ps);

// op_rev_rotate.c
void	rev_rotate_stack(t_stack **root);
void	rra(t_puswap *ps);
void	rrb(t_puswap *ps);
void	rrr(t_puswap *ps);

// index.c
// void	index_list(t_stack **root, int list_size);
void	index_list(t_puswap *ps);
t_stack	*get_nxtmin_node(t_stack *cur, int min, int new_max, int index);

// sorting.c
// void	start_sorting(t_stack **a, t_stack **b);
// void	sort_three(t_stack **a);
// void	sort_five(t_stack **a, t_stack **b, int list_size);
// void	get_next_min(t_stack **a, int min);
// void	execute_rotation(t_stack **a, int *cost);
void	start_sorting(t_puswap *ps);
void	sort_three(t_puswap *ps);
void	sort_five(t_puswap *ps);
void	get_next_min(t_puswap *ps, int new_min);
void	execute_rotation(t_puswap *ps, int *cost);

// algorithm.c
// void	radix_sort(t_stack **a, t_stack **b, int list_size);
void	radix_sort(t_puswap *ps);
int		get_bits(int list_size);
int		ft_power(int base, int exp);

// utils.c
// void	frexit(char *str, t_stack **root, char **split, int ec);
// void	print_stack_contents(t_stack *root);
// void	print_stacks(t_stack *a, t_stack *b);
void	frexit(char *str, t_puswap *ps, char **split, int ec);
void	print_stack_contents(t_stack *root);
void	print_stacks(t_puswap *ps);

#endif
