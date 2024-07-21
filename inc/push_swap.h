/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:36:33 by pamatya           #+#    #+#             */
/*   Updated: 2024/07/22 01:21:49 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/includes/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
void	parse_and_handle_errors(t_puswap *ps, int argc, char **argv);
void	parse_numstr(t_puswap *ps, char *num_str);
void	parse_nums(t_puswap *ps, char **argv);
long	ft_atol(const char *str);

// error_checks.c
void	check_digits_numstr(t_puswap *ps, char *num_str);
void	check_digits_argv(t_puswap *ps, char **argv);
void	avoid_long(t_puswap *ps);
void	avoid_duplicates(t_puswap *ps);
void	avoid_lesinvalides(t_puswap *ps, int argc, char **argv);

// list_fns.c: functions adapted from libft
t_stack	*ft_stack_new(long lnum);
t_stack	*ft_stack_last(t_stack *stk);
void	ft_stack_addback(t_stack **root, t_stack *new);
int		ft_stack_size(t_stack *root);
void	ft_stack_free(t_stack **root);

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
void	index_list(t_puswap *ps);
t_stack	*get_nxtmin_node(t_stack *cur, int min, int new_max, int index);

// sorting.c
void	start_sorting(t_puswap *ps);
void	sort_three(t_puswap *ps);
void	sort_five(t_puswap *ps);
void	get_next_min(t_puswap *ps, int new_min);
void	execute_rotation(t_puswap *ps, int *cost);

// algorithm.c
void	radix_sort(t_puswap *ps);
void	sort_bit(t_puswap *ps, int *list, int bit);
int		get_bits(int list_size);

// stack_info.c
int		is_sorted(t_stack *root);
int		is_descending(t_stack *stk_b);
int		ft_stack_min(t_stack *root);
int		ft_stack_max(t_stack *root);

// utils.c
int		ft_power(int base, int exp);
void	frexit(char *str, t_puswap *ps, char **split, int ec);

#endif
