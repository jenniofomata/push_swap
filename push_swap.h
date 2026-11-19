/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10
# define OP_NB 11

# define ST_SIMPLE 0
# define ST_MEDIUM 1
# define ST_COMPLEX 2
# define ST_ADAPTIVE 3

# define M_SELECT 0
# define M_CHUNK 1
# define M_RADIX 2
# define M_SMALL 3
# define M_LIS 4

# define CHUNK_MUL 2

typedef struct s_stack
{
	int	*v;
	int	size;
}	t_stack;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	int		n;
	int		strategy;
	int		chosen;
	int		bench;
	int		total;
	int		ops[OP_NB];
	double	disorder;
}	t_ps;

int		is_sep(char c);
int		is_flag(const char *arg, const char *name);

int		parse_flags(t_ps *ps, int ac, char **av);
int		count_nums(const char *s);
int		build_stack(t_ps *ps, int ac, char **av);
int		read_num(const char *s, int *pos, int *out);

void	init_ps(t_ps *ps);
int		alloc_stacks(t_ps *ps, int n);
int		has_duplicates(t_ps *ps);
int		normalize(t_ps *ps);

void	free_ps(t_ps *ps);
void	error_exit(t_ps *ps);

void	st_swap(t_stack *s);
void	st_rotate(t_stack *s);
void	st_rev_rotate(t_stack *s);
void	st_push(t_stack *from, t_stack *to);
void	emit(t_ps *ps, int op);

void	op_sa(t_ps *ps);
void	op_sb(t_ps *ps);
void	op_ss(t_ps *ps);
void	op_pa(t_ps *ps);
void	op_pb(t_ps *ps);
void	op_ra(t_ps *ps);
void	op_rb(t_ps *ps);
void	op_rr(t_ps *ps);
void	op_rra(t_ps *ps);
void	op_rrb(t_ps *ps);
void	op_rrr(t_ps *ps);

int		is_sorted(t_stack *s);
void	sort(t_ps *ps);
int		min_index(t_stack *s);
int		max_index(t_stack *s);
void	rot_a_to(t_ps *ps, int idx);
void	rot_b_to(t_ps *ps, int idx);
void	push_back_max(t_ps *ps);
void	sort_simple(t_ps *ps);
void	sort_medium(t_ps *ps);
void	sort_complex(t_ps *ps);
void	sort_small(t_ps *ps);
void	sort_lis(t_ps *ps);
int		pick_method(t_ps *ps);
int		ft_abs(int n);
void	apply_both(t_ps *ps, int *ta, int *tb);
void	apply_rest(t_ps *ps, int ta, int tb);
void	insert_all(t_ps *ps);

double	compute_disorder(t_ps *ps);
void	print_bench(t_ps *ps);
void	put_percent(double d);
void	put_op(char *label, int n);
void	put_strategy(int s);
void	put_class(int m);
void	put_method(int m);

#endif
