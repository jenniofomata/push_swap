/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pick_method(t_ps *ps)
{
	if (ps->n <= 5)
	{
		return (M_SMALL);
	}
	if (ps->disorder < 0.2)
	{
		return (M_LIS);
	}
	if (ps->disorder < 0.5)
	{
		return (M_CHUNK);
	}
	return (M_RADIX);
}
