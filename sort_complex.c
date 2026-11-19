/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((n - 1) >> bits)
	{
		bits++;
	}
	return (bits);
}

static void	radix_pass(t_ps *ps, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = ps->a.size;
	while (i < size)
	{
		if (((ps->a.v[0] >> bit) & 1) == 0)
			op_pb(ps);
		else
			op_ra(ps);
		i++;
	}
	while (ps->b.size > 0)
	{
		op_pa(ps);
	}
}

void	sort_complex(t_ps *ps)
{
	int	bit;
	int	bits;

	bits = max_bits(ps->n);
	bit = 0;
	while (bit < bits && !is_sorted(&ps->a))
	{
		radix_pass(ps, bit);
		bit++;
	}
}
