/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_counts(t_ps *ps)
{
	ft_putstr_fd("[bench] ", 2);
	put_op("sa", ps->ops[OP_SA]);
	put_op("sb", ps->ops[OP_SB]);
	put_op("ss", ps->ops[OP_SS]);
	put_op("pa", ps->ops[OP_PA]);
	put_op("pb", ps->ops[OP_PB]);
	ft_putstr_fd("\n[bench] ", 2);
	put_op("ra", ps->ops[OP_RA]);
	put_op("rb", ps->ops[OP_RB]);
	put_op("rr", ps->ops[OP_RR]);
	put_op("rra", ps->ops[OP_RRA]);
	put_op("rrb", ps->ops[OP_RRB]);
	put_op("rrr", ps->ops[OP_RRR]);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_ps *ps)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_percent(ps->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	put_strategy(ps->strategy);
	if (ps->strategy == ST_ADAPTIVE)
	{
		put_method(ps->chosen);
	}
	ft_putstr_fd(" / ", 2);
	put_class(ps->chosen);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(ps->total, 2);
	ft_putstr_fd("\n", 2);
	print_counts(ps);
}
