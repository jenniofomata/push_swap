/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lis_lengths(t_stack *a, int *len)
{
	int	i;
	int	j;

	i = a->size - 1;
	while (i >= 0)
	{
		len[i] = 1;
		j = i + 1;
		while (j < a->size)
		{
			if (a->v[j] > a->v[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
			}
			j++;
		}
		i--;
	}
}

static int	find_best(int *len, int size)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < size)
	{
		if (len[i] > len[best])
		{
			best = i;
		}
		i++;
	}
	return (best);
}

static void	mark_keep(t_stack *a, int *len, int *keep)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		keep[i] = 0;
		i++;
	}
	i = find_best(len, a->size);
	keep[i] = 1;
	j = i + 1;
	while (j < a->size)
	{
		if (len[j] == len[i] - 1 && a->v[j] > a->v[i])
		{
			keep[j] = 1;
			i = j;
		}
		j++;
	}
}

static void	strip_to_lis(t_ps *ps, int *keep)
{
	int	i;
	int	size;

	i = 0;
	size = ps->a.size;
	while (i < size)
	{
		if (keep[i])
			op_ra(ps);
		else
			op_pb(ps);
		i++;
	}
}

void	sort_lis(t_ps *ps)
{
	int	*len;
	int	*keep;

	len = ft_calloc(ps->n, sizeof(int));
	keep = ft_calloc(ps->n, sizeof(int));
	if (!len || !keep)
	{
		free(len);
		free(keep);
		sort_medium(ps);
		return ;
	}
	lis_lengths(&ps->a, len);
	mark_keep(&ps->a, len, keep);
	strip_to_lis(ps, keep);
	free(len);
	free(keep);
	insert_all(ps);
}
