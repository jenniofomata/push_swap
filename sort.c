/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (s->v[i] > s->v[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	sort(t_ps *ps)
{
	ps->chosen = ps->strategy;
	if (ps->strategy == ST_ADAPTIVE)
	{
		ps->chosen = pick_method(ps);
	}
	if (ps->n < 2 || is_sorted(&ps->a))
	{
		return ;
	}
	if (ps->chosen == M_SMALL)
		sort_small(ps);
	else if (ps->chosen == M_LIS)
		sort_lis(ps);
	else if (ps->chosen == M_CHUNK)
		sort_medium(ps);
	else if (ps->chosen == M_RADIX)
		sort_complex(ps);
	else
		sort_simple(ps);
}
