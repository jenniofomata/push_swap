/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	count_inversions(t_ps *ps)
{
	long	mistakes;
	int		i;
	int		j;

	mistakes = 0;
	i = 0;
	while (i < ps->n)
	{
		j = i + 1;
		while (j < ps->n)
		{
			if (ps->a.v[i] > ps->a.v[j])
			{
				mistakes++;
			}
			j++;
		}
		i++;
	}
	return (mistakes);
}

double	compute_disorder(t_ps *ps)
{
	long	pairs;

	pairs = (long)ps->n * (long)(ps->n - 1) / 2;
	if (pairs <= 0)
	{
		return (0.0);
	}
	return ((double)count_inversions(ps) / (double)pairs);
}
