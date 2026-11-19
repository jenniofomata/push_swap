/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_ps *ps)
{
	st_rotate(&ps->a);
	emit(ps, OP_RA);
}

void	op_rb(t_ps *ps)
{
	st_rotate(&ps->b);
	emit(ps, OP_RB);
}

void	op_rr(t_ps *ps)
{
	st_rotate(&ps->a);
	st_rotate(&ps->b);
	emit(ps, OP_RR);
}
