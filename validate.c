/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_ps *ps)
{
	int	i;

	ps->a.v = NULL;
	ps->a.size = 0;
	ps->b.v = NULL;
	ps->b.size = 0;
	ps->n = 0;
	ps->strategy = ST_ADAPTIVE;
	ps->chosen = ST_ADAPTIVE;
	ps->bench = 0;
	ps->total = 0;
	ps->disorder = 0.0;
	i = 0;
	while (i < OP_NB)
	{
		ps->ops[i] = 0;
		i++;
	}
}

int	alloc_stacks(t_ps *ps, int n)
{
	ps->a.v = ft_calloc(n, sizeof(int));
	ps->b.v = ft_calloc(n, sizeof(int));
	if (!ps->a.v || !ps->b.v)
	{
		return (0);
	}
	return (1);
}

int	has_duplicates(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->n)
	{
		j = i + 1;
		while (j < ps->n)
		{
			if (ps->a.v[i] == ps->a.v[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	fill_ranks(t_ps *ps, int *rk)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->n)
	{
		rk[i] = 0;
		j = 0;
		while (j < ps->n)
		{
			if (ps->a.v[j] < ps->a.v[i])
			{
				rk[i]++;
			}
			j++;
		}
		i++;
	}
}

int	normalize(t_ps *ps)
{
	int	*rk;
	int	i;

	rk = ft_calloc(ps->n, sizeof(int));
	if (!rk)
	{
		return (0);
	}
	fill_ranks(ps, rk);
	i = 0;
	while (i < ps->n)
	{
		ps->a.v[i] = rk[i];
		i++;
	}
	free(rk);
	return (1);
}
