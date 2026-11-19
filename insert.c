/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	target_pos(t_stack *a, int v)
{
	int	i;
	int	prev;

	i = 0;
	while (i < a->size)
	{
		prev = a->v[(i + a->size - 1) % a->size];
		if (prev < v && v < a->v[i])
		{
			return (i);
		}
		i++;
	}
	return (min_index(a));
}

static int	rot_steps(int idx, int size)
{
	if (idx <= size - idx)
	{
		return (idx);
	}
	return (idx - size);
}

static int	combo_cost(int ta, int tb)
{
	if ((ta >= 0 && tb >= 0) || (ta <= 0 && tb <= 0))
	{
		if (ft_abs(ta) > ft_abs(tb))
		{
			return (ft_abs(ta));
		}
		return (ft_abs(tb));
	}
	return (ft_abs(ta) + ft_abs(tb));
}

static int	best_index(t_ps *ps, int *ta, int *tb)
{
	int	j;
	int	best;
	int	cost;
	int	bestcost;

	best = 0;
	bestcost = 2147483647;
	j = 0;
	while (j < ps->b.size)
	{
		*ta = rot_steps(target_pos(&ps->a, ps->b.v[j]), ps->a.size);
		*tb = rot_steps(j, ps->b.size);
		cost = combo_cost(*ta, *tb);
		if (cost < bestcost)
		{
			bestcost = cost;
			best = j;
		}
		j++;
	}
	*ta = rot_steps(target_pos(&ps->a, ps->b.v[best]), ps->a.size);
	*tb = rot_steps(best, ps->b.size);
	return (best);
}

void	insert_all(t_ps *ps)
{
	int	ta;
	int	tb;

	while (ps->b.size > 0)
	{
		best_index(ps, &ta, &tb);
		apply_both(ps, &ta, &tb);
		apply_rest(ps, ta, tb);
		op_pa(ps);
	}
	rot_a_to(ps, min_index(&ps->a));
}
