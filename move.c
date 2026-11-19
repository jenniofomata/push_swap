/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_stack *s)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->v[i] < s->v[best])
		{
			best = i;
		}
		i++;
	}
	return (best);
}

int	max_index(t_stack *s)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->v[i] > s->v[best])
		{
			best = i;
		}
		i++;
	}
	return (best);
}

void	rot_a_to(t_ps *ps, int idx)
{
	int	i;
	int	up;

	i = 0;
	up = ps->a.size - idx;
	if (idx <= up)
	{
		while (i < idx)
		{
			op_ra(ps);
			i++;
		}
	}
	else
	{
		while (i < up)
		{
			op_rra(ps);
			i++;
		}
	}
}

void	rot_b_to(t_ps *ps, int idx)
{
	int	i;
	int	up;

	i = 0;
	up = ps->b.size - idx;
	if (idx <= up)
	{
		while (i < idx)
		{
			op_rb(ps);
			i++;
		}
	}
	else
	{
		while (i < up)
		{
			op_rrb(ps);
			i++;
		}
	}
}

void	push_back_max(t_ps *ps)
{
	while (ps->b.size > 0)
	{
		rot_b_to(ps, max_index(&ps->b));
		op_pa(ps);
	}
}
