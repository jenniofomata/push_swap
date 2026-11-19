/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_ps *ps)
{
	int	x;
	int	y;
	int	z;

	x = ps->a.v[0];
	y = ps->a.v[1];
	z = ps->a.v[2];
	if (x > y && y < z && x < z)
		op_sa(ps);
	else if (x > y && y < z && x > z)
		op_ra(ps);
	else if (x < y && y > z && x > z)
		op_rra(ps);
	else if (x > y && y > z)
	{
		op_sa(ps);
		op_rra(ps);
	}
	else if (x < y && y > z && x < z)
	{
		op_sa(ps);
		op_ra(ps);
	}
}

void	sort_small(t_ps *ps)
{
	if (ps->a.size == 2)
	{
		op_sa(ps);
		return ;
	}
	while (ps->a.size > 3)
	{
		rot_a_to(ps, min_index(&ps->a));
		op_pb(ps);
	}
	sort_three(ps);
	while (ps->b.size > 0)
	{
		op_pa(ps);
	}
}
