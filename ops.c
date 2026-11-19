/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_ps *ps)
{
	st_swap(&ps->a);
	emit(ps, OP_SA);
}

void	op_sb(t_ps *ps)
{
	st_swap(&ps->b);
	emit(ps, OP_SB);
}

void	op_ss(t_ps *ps)
{
	st_swap(&ps->a);
	st_swap(&ps->b);
	emit(ps, OP_SS);
}

void	op_pa(t_ps *ps)
{
	st_push(&ps->b, &ps->a);
	emit(ps, OP_PA);
}

void	op_pb(t_ps *ps)
{
	st_push(&ps->a, &ps->b);
	emit(ps, OP_PB);
}
