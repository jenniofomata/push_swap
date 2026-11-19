/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int n)
{
	int	r;

	r = 1;
	while ((r + 1) * (r + 1) <= n)
	{
		r++;
	}
	return (r * CHUNK_MUL);
}

static int	count_le(t_stack *s, int hi)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < s->size)
	{
		if (s->v[i] <= hi)
		{
			c++;
		}
		i++;
	}
	return (c);
}

static void	bring_target(t_ps *ps, int hi)
{
	int	f;
	int	b;

	f = 0;
	while (f < ps->a.size && ps->a.v[f] > hi)
	{
		f++;
	}
	b = 0;
	while (b < ps->a.size && ps->a.v[ps->a.size - 1 - b] > hi)
	{
		b++;
	}
	if (f <= b + 1)
		rot_a_to(ps, f);
	else
		rot_a_to(ps, ps->a.size - 1 - b);
}

void	sort_medium(t_ps *ps)
{
	int	csize;
	int	hi;

	csize = chunk_size(ps->n);
	hi = csize - 1;
	while (ps->a.size > 0)
	{
		if (count_le(&ps->a, hi) == 0)
			hi += csize;
		else
		{
			bring_target(ps, hi);
			op_pb(ps);
			if (ps->b.v[0] <= hi - csize / 2)
				op_rb(ps);
		}
	}
	push_back_max(ps);
}
