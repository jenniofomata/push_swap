/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}

void	apply_both(t_ps *ps, int *ta, int *tb)
{
	while (*ta > 0 && *tb > 0)
	{
		op_rr(ps);
		(*ta)--;
		(*tb)--;
	}
	while (*ta < 0 && *tb < 0)
	{
		op_rrr(ps);
		(*ta)++;
		(*tb)++;
	}
}

void	apply_rest(t_ps *ps, int ta, int tb)
{
	while (ta > 0)
	{
		op_ra(ps);
		ta--;
	}
	while (ta < 0)
	{
		op_rra(ps);
		ta++;
	}
	while (tb > 0)
	{
		op_rb(ps);
		tb--;
	}
	while (tb < 0)
	{
		op_rrb(ps);
		tb++;
	}
}
