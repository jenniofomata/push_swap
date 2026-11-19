/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_ps *ps)
{
	st_rev_rotate(&ps->a);
	emit(ps, OP_RRA);
}

void	op_rrb(t_ps *ps)
{
	st_rev_rotate(&ps->b);
	emit(ps, OP_RRB);
}

void	op_rrr(t_ps *ps)
{
	st_rev_rotate(&ps->a);
	st_rev_rotate(&ps->b);
	emit(ps, OP_RRR);
}
